#!/bin/bash

CLASS=$1
SRC_DIR="src"
H_DIR="include"
CLASS_CPP=$CLASS".cpp"
CLASS_HPP=$CLASS".hpp"
CLASS_GUARD_NAME=`echo "__"$CLASS"_HPP__" | tr a-z A-Z`

if [ "$1" = "main" ]; then
	if [ -d $SRC_DIR ]; then
		if [ -e $SRC_DIR"/main.cpp" ]; then
			echo "Main file already exists."
		else
			echo "int	main(int argc, char **argv)
{
	return (0);
}" >> $SRC_DIR"/main.cpp"
		fi
	fi
	exit 0
fi

if [ ! -d $SRC_DIR ] || [ ! -d $H_DIR ]; then
	echo "Create $SRC_DIR and $H_DIR dirs first"
	exit 0
fi

if [ -e $SRC_DIR"/"$CLASS_CPP ] || [ -e $SRC_DIR"/"$CLASS_HPP ]; then
	echo "Class $CLASS already exists!"
else
# 	echo \
# "\
# /* -------------------------------- */
# /* |                              | */
# /* |     HEADER                   | */
# /* |                              | */
# /* |                              | */
# /* -------------------------------- */
# " \
# >> $SRC_DIR"/"$CLASS_CPP

echo "#include \"$CLASS_HPP\"

$CLASS::$CLASS()
{

}

$CLASS::$CLASS($CLASS const &o)
{

}

$CLASS::~$CLASS()
{

}

$CLASS & $CLASS::operator=($CLASS const &o)
{

}" >> $SRC_DIR"/"$CLASS_CPP

	echo "#pragma once
#ifndef $CLASS_GUARD_NAME
#define $CLASS_GUARD_NAME

class $CLASS
{
	public:
		$CLASS();
		$CLASS($CLASS const &o);
		~$CLASS();
		$CLASS & operator=($CLASS const &o);
};
#endif
" >> $H_DIR"/"$CLASS_HPP
fi
