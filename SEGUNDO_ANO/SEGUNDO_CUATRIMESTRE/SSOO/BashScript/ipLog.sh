#!/bin/bash

###############################################################################
#                             SISTEMAS OPERATIVOS                             #
#                           PRACTICA 1 - SCRIPTING                            #
#                                                                             #
#                            GABRIEL MORALES DATO                             #
###############################################################################

###############################################################################
#                                  IPLOG.SH                                   #
#                                                                             #
# OBJETIVO: Detectar los intentos de login en el equipo leyendo los logs del  #
# sistema.                                                                    #
#                                                                             #
# PASOS:                                                                      #
#  1. Comprobar los argumentos.                                               #
#       -Comprobar que el numero de argumentos es valido.                     #
#       -Comprobar que los argumentos siguen la estructura:                   #
#          > IP PATH                                                          #
#          > IP                                                               #
#          > PATH                                                             #
#          > Ningun argumento                                                 #
#       -Comprobar la validez de los argumentos:                              #
#          > La IP sigue un formato valido                                    #
#          > La ruta (relativa o absoluta) es valida y existe.                #
#       -Si las comprobaciones anteriores son exitosas, se guardan los        #
#        argumentos en variables. En caso contrario se muestra un error.      #
#  2. Imprimir informacion del sistema:                                       #
#       -Mostrar el nombre de usuario que ejecuta el script                   #
#       -Mostrar la fecha y hora de ejecucion                                 #
#       -Mostrar la version de bash utilizada                                 #
#  3. Buscar la IP en los logs                                                #
#       -Dependiendo del numero y tipo de argumentos la ejecucion sera        #
#        diferente.                                                           #
###############################################################################

# Si no se ha ejecutado como root, se lanza una advertencia
if [[ ! "$USER" = "root" ]];
then
  echo -e "Advertencia: el script no se ha ejecutado como root, la
funcionalidad del programa puede estar imcompleta.\n";
fi;

# FicheroLog es una variable que va a contener la ruta absoluta al fichero de
# log
ficheroLog=/var/log/ipLog.log;
# Antes de comenzar con la ejecucion, se limpia el contenido del fichero de log
# Se agrega permisos de escritura para que se pueda grabar en el. ESto solo es
# efectivo en la primera ejecucion del script.
echo "" > $ficheroLog;
chmod 777 $ficheroLog;


# 1. COMPROBAR LOS ARGUMENTOS
nargs=$#;    # $# -> numero de argumentos
args=$@;     # $@ -> lista de argumentos

ip="";       # Ip que se va a buscar en los logs. En caso de no indicarla, se
             # usa la que mas apariciones tenga en /var/log/auth.log.
path="";     # Ruta donde se van a buscar los logs

valido=true; # Cambia a false si un argumento no es valido
log="";      # Lo voy a usar para imprimir mensajes en caso de errores o avisos

# Si solo se indica un argumento.
if [ $nargs = 1 ];
then
  # La siguiente linea comprueba que el parametro es una direccion ip. Para
  # ello hago uso de expresiones regulares: compruebo que haya siempre 4
  # numeros de longitud 1 a 3, separados por puntos y que contengan valores
  # del 0 al 9.
  #
  # La comprobacion del if se hace con [[ =~ ]], que es el patron para evaluar
  # expresiones regulares POSIX.
  if [[ $1 =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]];
  then
    ip=$1;
  # Para comprobar si es un path valido, se comprueba que no contenga
  # caracteres
  # nulos y no sea la cadena vacia. Todo lo demas es un path valido en Unix.
  elif [[ $1 =~ [^\0]+ ]];
  then
    # Se comprueba si el path existe en el sistema y es un directorio o fichero
    if [ ! -d "$1" ] && [ ! -f "$1" ];
    then
      valido=false;
      log="No se ha podido encontrar la ruta $1 en el sistema\n";
    else
      path=$1;
    fi;
  else
    log="El primer parametro no cumple el formato de una direccion IP o ruta
         absoluta o relativa.";
  fi;
# Si se indican dos argumentos
elif [ $nargs = 2 ];
then
  if [[ $1 =~ ^[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}$ ]];
  then
    ip=$1;
  else
    echo "La direccion IP $1 no se reconoce como valida" >> $ficheroLog;
    cat $ficheroLog;
    exit 1;
  fi;
  if [[ $2 =~ [^\0]+ ]];
  then
    if [ ! -d "$2" ];
    then
      valido=false;
      echo "No se ha podido encontrar la ruta $2 en el sistema" >> $ficheroLog;
      cat $ficheroLog;
      exit 1;
    else
      path=$2;
    fi;
  fi;
# Si el numero de argumentos es distinto de 0, 1 o 2
elif [ ! $nargs = 0 ];
then
  valido=false;
  log="Numero de argumentos no permitido.
        \nHa indicado: $nargs. Se requieren 0, 1 o 2.
        \nModo de uso:
        \n  ./ipLog.sh
        \n  ./ipLog.sh IP PATH
        \n  ./ipLog.sh IP
        \n  ./ipLog.sh PATH";
fi;

if $valido;
then
  if [ "$path" = "" ];
  then
    path="/var/log/auth.log" # Se agrega el fichero de logs por defecto.
  fi;
# En caso de no ser valido algunos de los argumentos, se imprime el mensaje
else
  # -e sirve para que echo detecte caracteres de escape (\n en este caso)
  echo -e $log >> $ficheroLog;
  # Se imprime la ejecucion, que se ha guardado en ipLog.log
  cat $ficheroLog;
  exit 1; # Termina la ejecucion del programa
fi;

# Se imprime informacion sobre los parametros.
if [ "$args" = "" ];
then
  parametros="ninguno.";
else
  parametros="$args";
fi;
echo -e "PARAMETROS ACEPTADOS: $parametros
IP: $ip
PATH: $path\n" >> $ficheroLog;


#  2. IMPRIMIR INFORMACION DEL SISTEMA
echo -e "Usuario que ha ejecutado el script: $USER
Fecha y hora de ejecucion: $(date)
Version de bash: $BASH_VERSION
\n\n----------EJECUCION DEL PROGRAMA----------\n" >> $ficheroLog;


# 3. BUSCAR LA IP EN LOS LOGS
function buscar() {
  # Array que va a contener los ficheros donde buscar la ip
  # La declaro como local para que se use solo en esta funcion
  local ficheros;

  # Si el path indicado es un fichero, se agrega al listado
  if [[ -f $path ]];
    then
    ficheros+=$path;
  # Si el path indicado es un directorio, se buscan ficheros con extension
  # .log en el path, y se agregan al listado
  elif [[ -d $path ]];
    then
    cd $path;
    # Al buscar los ficheros, redirigo la salida de errores a /dev/null para
    # que no se muestre por pantalla, ya que la comprobacion de si esta
    # variable esta vacia la hago mas adelante.
    ficheros+=$(find *.log -type f 2> /dev/null);
  fi;
  # Se procede a buscar en los ficheros

  # OPCION 1: SE INDICA EL PATH Y LA IP
  if [ $nargs = 2 ];
  then
    if [[ -d $path ]];
    then
      echo "Buscando logs en $path..." >> $ficheroLog;
      cd $path;
    fi;
    # Si el directorio esta vacio o no contiene ficheros .log, se aborta la
    # ejecucion del programa
    if [ "$ficheros" = "" ];
    then
      echo "No se han encontrado ficheros .log en $path." >> $ficheroLog;
      # Se imprime la ejecucion, que se ha guardado en ipLog.log
      cat $ficheroLog;
      exit 1;
    fi;
    for fichero in $ficheros;
    do
      log="Buscando en $fichero la IP $ip...";
      # Se convierte la IP a formato ip-x-x-x-x, que es el que contienen los
      # logs
      ipGuiones="ip-$ip";                      # Se agrega el prefijo 'ip-'
      ipGuiones=$(echo "$ipGuiones" | tr . -); # Se sustituye '.' por '-'
      # contieneLaIP es una cadena de texto que contiene todas las lineas del
      # fichero que contienen la IP, por lo que si el fichero no contiene la IP
      # esta variables valdra ""
      contieneLaIP=$(cat $fichero | grep $ipGuiones);
      if [ ! "$contieneLaIP" = "" ];
      then
        log+="Encontrada.";
      else
        log+="No encontrada.";
      fi;
      echo -e $log >> $ficheroLog;
    done;

  # OPCION 2. SOLO SE INDICA LA IP
  elif [ ! "$ip" = "" ] && [ "$path" = "/var/log/auth.log" ];
  then
    # Primero se pasa la IP a formato ip-x-x-x-x, que es el usado en los logs
      ipGuiones="ip-$ip";                      # Se agrega el prefijo 'ip-'
      ipGuiones=$(echo "$ipGuiones" | tr . -); # Se sustituye '.' por '-'
    # Se cuenta el numero de apariciones de la IP en el PATH
    # Uso cat porque PATH siempre va a ser /var/log/auth.log, por lo que no
    # hace falta comprobar si es fichero o directorio.
    # Uso grep -w para que no detecte substrings, por ejemplo si se busca
    # 10.10.10.10, no contara 10.10.10.1 como aparicion
    apariciones=$(cat $path | grep -w $ipGuiones | wc -l);
    echo -e "Buscando la IP $ip en $path...
Aparece un total de $apariciones veces" >> $ficheroLog;

  # OPCION 3: SOLO SE INDICA EL PATH
  elif [ "$ip" = "" ] && [ ! "$path" = "" ] && [ $nargs = 1 ];
  then
    # Se busca la ultima IP que aparece en /var/log/auth.log
    # regexAuthLog contiene la expresion regular que siguen las ips en los
    # ficheros de log.
    regexpAuthLog="ip-[0-9]{1,3}-[0-9]{1,3}-[0-9]{1,3}-[0-9]{1,3}";
    ipAuthLog=$(grep -E -o -w $regexpAuthLog /var/log/auth.log | tail -n 1);
    # Se comprueba si se ha encontrado alguna ip
    # Si no se ha encontrado, se aborta la ejecucion
    if [ "$ipAuthLog" = "" ];
    then
      echo "No se han encontrado IPs en /var/log/auth.log" >> $ficheroLog;
      # Se imprime la ejecucion, que se ha guardado en ipLog.log
      cat $ficheroLog;
      exit 1;
    # Si se encuentra, se reemplaza para que siga un patron x.x.x.x y se
    # continua la ejecucion.
    else
      ipGuiones=$ipAuthLog; # Contiene la ip con guiones, para luego buscarla
                            # en los siguientes documentos
      ipAuthLog=${ipAuthLog:3};                # Se quita el prefijo 'ip-'
      ipAuthLog=$(echo "$ipAuthLog" | tr - .); # Se sustituye '-' por '.'
      echo -e "Ultima IP que aparece en /var/log/auth.log: $ipAuthLog\n" >> \
        $ficheroLog;
    fi;
    # Se comprueba si hay ficheros .log o no
    if [ "$ficheros" = "" ];
    then
      log="No hay ficheros .log en $path";
      echo -e $log >> $ficheroLog;
    else
      for fichero in $ficheros;
      do
        log="Buscando en $fichero la IP $ipAuthLog... ";
        # contieneLaIP es una cadena de texto que contiene todas las lineas del
        # fichero que contienen la IP, por lo que si el fichero no contiene la IP
        # esta variables valdra ""
        contieneLaIP=$(cat $fichero | grep -w $ipGuiones);
        if [ ! "$contieneLaIP" = "" ];
        then
          log+="Encontrada.";
        else
          log+="No encontrada.";
        fi;
        echo -e $log >> $ficheroLog;
      done;
    fi;

  # OPCION 4: NO SE INDICAN ARGUMENTOS
  #Buscaremos en las últimas 100 líneas del fichero
  #/var/log/auth.log cuál es la IPs que más aparece y el número de veces.
  elif [ $nargs = 0 ];
  then
    # regexAuthLog contiene la expresion regular que siguen las ips en los
    # ficheros de log.
    regexpAuthLog="ip-[0-9]{1,3}-[0-9]{1,3}-[0-9]{1,3}-[0-9]{1,3}";
    # ipsLog es un vector que va a contener todas las IPs que se encuentren en el
    # fichero /var/log/auth.log
    ipsLog=$(grep -o -w -E $regexpAuthLog $path | sort -u -f);
    # Por cada ip en ipsLog, se cuenta el numero de veces que aparece, y se
    # imprime la que mas apariciones tenga
    max=0; # Variable para ir calculando la IP que aparece mas veces
    ipMax="";
    for ip in $ipsLog;
    do
      apariciones=$(grep -o -i -w "$ip" "$path" | wc -l);
      if [ $apariciones -gt $max ];
      then
        max=$apariciones;
        ipMax=$ip;
      fi;
    done;
    # Se muestra la ip en formato x.x.x.x para imprimirla
    ipMax=${ipMax:3};                # Se quita el prefijo 'ip-'
    ipMax=$(echo "$ipMax" | tr - .); # Se sustituye '-' por '.'
    echo -e "Buscando IPs en $path...\n
La IP $ipMax es la que mas veces aparece, con un total de $max veces." >> $ficheroLog;
  fi;
}

buscar; # Llamada a la funcion principal
echo -e "\n\nEjecucion terminada sin errores." >> $ficheroLog;

# Toda la ejecucion se ha guardado en ipLog.log y ahora se imprime por pantalla
cat $ficheroLog;
