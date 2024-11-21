#!/bin/bash
if [ $# -ne 2 ]; then
    echo "Uso: $0 <ruta_del_archivo> <texto>"
    exit 1
fi

writefile=$1
writestr=$2

mkdir -p "$(dirname "$writefile")"
echo "$writestr" > "$writefile" || { echo "Error al crear el archivo."; exit 1; }

exit 0

