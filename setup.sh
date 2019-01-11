#!/bin/bash


if [ $# -ne 1 ]; then
    printf $0:
    printf " uso: ./setup.sh release|debug. \n"
    exit 1
fi



eleccion=$1


if [[ $eleccion = "release" || $eleccion = "debug" ]]; then

  if [ ! -d build ]; then
    mkdir build
  fi
  if [ ! -d install ]; then
    mkdir install
  fi

  printf "configurando en modo "
  printf $eleccion
  printf "\n"

  if [ ! -d build/$eleccion ]; then
   mkdir build/$eleccion
  fi
  if [ ! -d install/$eleccion ]; then
    mkdir install/$eleccion
  fi


  cd build/$eleccion
  cmake -DCMAKE_BUILD_TYPE=$eleccion ../../ -GNinja 



else

  printf "error: no se especifico una opcion valida.\n"

  exit 1

fi




