#!/bin/bash
numfiles=10
writestr="AELD_IS_FUN"
tempdir="/tmp/aeld-data"

rm -rf "$tempdir"
mkdir -p "$tempdir"

for i in $(seq 1 $numfiles); do
    ./finder-app/writer.sh "$tempdir/file$i.txt" "$writestr"
done

result=$(./finder-app/finder.sh "$tempdir" "$writestr")
expected="El número de ficheros es $numfiles y el número de líneas coincidentes es $numfiles"

if [ "$result" == "$expected" ]; then
    echo "Éxito"
else
    echo "Error: salida inesperada"
    exit 1
fi

