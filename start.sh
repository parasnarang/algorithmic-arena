if [ $# -lt 1 ]
then
    echo "Enter new program name"
    exit 1
fi
if [ ! -e $1 ]
then
mv *.cpp ../doneprogs/
cp src/template.cpp $1.cpp
rm -f input output
emacs -nw input output src/myalgo.h $1.cpp
else
emacs -nw input output src/myalgo.h $1
fi

