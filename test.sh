#!/bin/bash
if [ $# -lt 0 ]
then
    echo "Enter prog name"
    exit 1
fi

INPUTFILE=input
OUTPUTFILE=output
progname=myprog #`echo $1 | sed -e 's/^.*\\///'`

rm -f bin/algoout bin/$progname.o bin/diffout > /dev/null >> /dev/null

g++ -DJAI_ARENA -g *.cpp -o bin/$progname.o

if [ ! -e bin/$progname.o ]
then
    echo "\nCompilation Error\n"
    exit 1
fi

if [[ ! -e $INPUTFILE || ! -f $INPUTFILE ]]
then
    echo "[*] Could not find a valid input file. Redirecting to Terminal:"
    bin/$progname.o
    exit 1
else
    echo -n Time taken:
    time bin/$progname.o < $INPUTFILE > bin/algoout 2>&1
    echo -------------------------------
    echo
fi

if [[ -e $OUTPUTFILE && -f $OUTPUTFILE ]]
then
    diff $OUTPUTFILE bin/algoout > bin/diffout
    diffsize=`ls -l bin/diffout | cut -d' ' -f5`
    if [ $diffsize -eq 0 ]
    then
	echo Success!!
    else
	echo Failed!!
	echo "[*] ######  DIFF  ######"
	cat bin/diffout
	echo "    --------------------"
	echo
	echo "[*] ## EXPECTED OUTPUT ##"
	cat $OUTPUTFILE
	echo "    --------------------"
	echo 
	echo "[*] ## FOUND OUTPUT #####"
	cat bin/algoout
	echo "    --------------------"
    fi
else
    echo "[*] Could not find output file. Dumping to Terminal:"
    cat bin/algoout
fi