#!/bin/bash 
echo "Usage: sudo ./INSTALL-ACE+TAO-6.1.2.sh [INSTALL-DIR]"; 
echo "best to put it in /opt" 
ACETAO=ACE+TAO-6.3.2 
# To change to the latest available install change the ACETAO
# Tested and works with UBUNTU 10.04 and 12.04
if [ $# -eq 1 ]; then 
	INSTALL_DIR=$1; 
	else 
	INSTALL_DIR=~/; 
fi 
# check if script is run as root! 
echo "default run sudo ./INSTALL-ACE+TAO-6.1.2.sh ~/"; 
echo "Tested with Ubuntu-but in theory work on all linux! NJOY !"; 

# go to $INSTALL_DIR to install ACE+TAO into 
cd $INSTALL_DIR; 

# download ACE+TAO to current directory 
echo "Download: wget http://download.dre.vanderbilt.edu/previous_versions/$ACETAO.tar.gz"; 
wget http://download.dre.vanderbilt.edu/previous_versions/$ACETAO.tar.gz 
if [ "$?" -ne 0 ]; then echo "ERROR: download failed!"; exit 1; fi 

# rm possible former installation 
rm -rf ACE_wrappers; 
rm -rf $ACETAO; 

# extract archive 
echo "UNTAR: tar -xzf $ACETAO.tar.gz"; 
tar -xzf $ACETAO.tar.gz 
if [ "$?" -ne 0 ]; then echo "ERROR: extraction failed!"; exit 1; fi 

# set environment variables 
cd ACE_wrappers; 
echo "export ACE_ROOT=$PWD" >> ~/.bashrc 
source ~/.bashrc 
echo 'export TAO_ROOT=$ACE_ROOT/TAO' >> ~/.bashrc 
echo 'export LD_LIBRARY_PATH=$ACE_ROOT/lib:$LD_LIBRARY_PATH' >> ~/.bashrc 
source ~/.bashrc 
cd $ACE_ROOT; 
# create config.h file 
echo "Config.h create--- $ACE_ROOT/ace/config.h" 
echo "#include <ace/config-linux.h>" > $ACE_ROOT/ace/config.h 
echo "" >> $ACE_ROOT/ace/config.h 

# create platform_macros.GNU file 
echo "create platform_macros.GNU for linux--$ACE_ROOT/include/makeinclude/platform_macros.GNU"; 
echo "INSTALL_PREFIX = /usr/local" > $ACE_ROOT/include/makeinclude/platform_macros.GNU 
echo "include \$(ACE_ROOT)/include/makeinclude/platform_linux.GNU" >> $ACE_ROOT/include/makeinclude/platform_macros.GNU 
echo "" >> $ACE_ROOT/include/makeinclude/platform_macros.GNU 

# compile ace kernel 
cd $ACE_ROOT/ace; 
make -j3; 
if [ "$?" -ne 0 ]; then echo "FAILED to compile $ACE_ROOT/ace!"; exit 1; fi 

# compile gperf 
cd $ACE_ROOT/apps/gperf; 
make -j3; 
if [ "$?" -ne 0 ]; then echo "FAILED to compile $ACE_ROOT/apps/gperf!"; exit 1; fi 
 
cd $ACE_ROOT/ace; 
make install; 
if [ "$?" -ne 0 ]; then echo "FAILED to install $ACE_ROOT/ace!"; exit 1; fi 

# compile TAO 
cd $TAO_ROOT; 
make -j3; 
if [ "$?" -ne 0 ]; then echo "FAILED to compile $TAO_ROOT/TAO!"; exit 1; fi 

echo ""; 
echo "ACE+TAO successfully installed!!!";
