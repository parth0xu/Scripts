#!/bin/bash

#This script will give you the information of a file.

if [ $# -eq 0 ]
then  
    echo "USAGE: $0 [File]"
    exit 1
    fi
OWNER=`ls -la $1 | awk '{print $3}'`
SIZE=`ls -la $1 | awk '{print $5}'`
MONTH=`ls -la $1 | awk '{print $6 " " $7}'`
TIME=`ls -la $1 | awk '{print $8}'`

echo "File Name:$1"
echo
echo "Owner:$OWNER "
echo "Size:$SIZE"
echo "This file was created on $Month at $Time"
echo "File Type: `file $1`"
echo
echo "Permissions"

#Checking readable Permissions
if [ -r $1 ]
then 
   echo "Readable=TRUE"
   else
   echo "READABLE=FALSE"
   fi

# Checking writable permission

if [ -w $1 ]
then 
   echo "WRITABLE=TRUE"
   else
   echo "WRITABLE=FALSE"
   fi

# Checking for executable permission

if [ -x $1 ]
then 
   echo "EXECUTABLE=TRUE"
   else
   echo "EXECUTABLE=FALSE"
   fi
