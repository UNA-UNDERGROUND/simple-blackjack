#!/bin/bash

if [ ! -d build ]; then
  echo por favor ejecute setup.sh primero
  exit 1
fi

if [ $# -ne 1 ]; then
    printf $0:
    printf " uso: ./build.sh release|debug. \n"
    exit 1
fi

eleccion=$1

cd build


if [ $eleccion = "release" ] || [ $eleccion = "debug" ]; then

  printf "compilando en modo "
  printf $eleccion
  printf "\n"

  cd $eleccion
  ninja
  

  if [ $? != 0 ]; then

  printf "no se pudo compilar el ejecutable!\n";

  exit 1;

  fi

  if [ ! -f BlackJack ]; then
      printf "no se ha encontrado el ejecutable!\n"
      exit 1
  else


  if [ ! -d ../../install/$eleccion ]; then
    mkdir ../../install/$eleccion
  fi

  cp BlackJack ../../install/$eleccion/BlackJack
  cd ../../install/$eleccion

fi
else

  printf "error: no se especifico una opcion valida.\n"

  exit 1

fi