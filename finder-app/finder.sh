#!/bin/bash
if [ $# -ne 2 ]; then
    echo "Uso: $0 <directorio> <cadena>"
    exit 1
fi

filesdir=$1
searchstr=$2

if [ ! -d "$filesdir" ]; then
    echo "Error: $filesdir no es un directorio válido."
    exit 1
fi

num_files=$(find "$filesdir" -type f | wc -l)
num_lines=$(grep -r "$searchstr" "$filesdir" | wc -l)

echo "El número de ficheros es $num_files y el número de líneas coincidentes es $num_lines"
exit 0

