#!/bin/bash
if ! test -f ex2.txt
then
  echo "1" > ex2.txt
fi

while [ 1 == 1 ]
do
  if ln ex2.txt ex2.lock 2>/dev/null
  then
  a=`tail -1 ex2.txt`
  a="$(echo "$a"|tr -d '\n\r')"
  a=$(($a + 1))
  echo $a >> ex2.txt
  rm ex2.lock
  fi
done