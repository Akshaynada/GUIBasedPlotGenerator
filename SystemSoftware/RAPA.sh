#!/bin/sh

FILE1="Attr.txt"
FILE2="Output.txt"
if [ -f $FILE1 ] || [ -f $FILE2 ];
then
echo "File $FILE exists"
	rm Attr.txt Output.txt
fi

./RAPA

if [ -f $FILE1 ] && [ -f $FILE2 ];
then
echo "File $FILE exists"
./aks.out
else
echo "File $FILE does not exists"
fi 

exit 0
