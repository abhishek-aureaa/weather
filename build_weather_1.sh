#use ubuntu 18.04 which can be downloaded from https://www.ubuntu.com/download/server ......& login as root 
#Try to use the The OS  with desktop already installed. Though the apt-get command to install the desktop is below in the script, but that would take lot of time..
#...if the desktop is not already installed

cd ~
sudo dpkg --configure -a
sudo apt-get update
sudo apt-get install cmake -y

sudo apt install libcanberra-gtk* -y
sudo apt-get install libcanberra-gtk* -y
#rm -rf ~/OhioLdapPlugin
#rm -rf ~/weather
#git clone https://github.com/abhishek-aurea/OhioLdapPlugin #need to give all permission to every one here
#git clone https://github.com/abhishek-aureaa/weather.git #need to give all permission to every one here
export HOME=~/weather
cd ~
#chmod +x ./build.sh
#cp -p OhioLdapPlugin/*.c ./
#cp -p OhioLdapPlugin/build-gtk.sh ./
rm -rf ~/Weather
rm -rf ~/cmake

mkdir Weather
cd Weather
wget https://github.com/ruslo/weather/archive/v1.2.0.tar.gz
tar xf v1.2.0.tar.gz
cd weather-1.2.0

sudo apt-get install build-essential -y

###commented from here 
#mkdir ~/cmake
#cd ~/cmake
#wget http://www.cmake.org/files/v3.2/cmake-3.2.2.tar.gz
#tar -xvf cmake-3.2.2.tar.gz
#cd cmake-3.2.2
#./configure
#make
#export PATH=~/cmake/cmake-3.2.2/bin:$PATH
###commented till here

cd ~/Weather/weather-1.2.0
sudo apt-get install python -y

cat README.md | sed 's,http://github.com/ruslo/sober,https://github.com/abhishek-aurea/OhioLdapPlugin,g' > R.md
mv R.md README.md
cd ./Source/weather/ui/ios/views
cat About.mm | sed 's,http://github.com/ruslo/sober,https://github.com/abhishek-aurea/OhioLdapPlugin,g' > x
mv x About.mm
cd -
#cd ..
echo 'set(CMAKE_CXX_COMPILER "g++")' >> CMakeLists.txt
echo 'set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")' >> CMakeLists.txt
cd ..
sudo apt-get install gcc -y
sudo apt-get install g++ -y
sudo apt-get update
sudo apt-get install cmake -y
cd ~/Weather
mkdir -p to/hunter/root/
mkdir -p to/toolchains
sudo apt-get install doxygen -y
export DOXYGEN_EXECUTABLE=/usr/bin/doxygen
sudo apt-get install graphviz -y
export HUNTER_ROOT=${PWD}/to/hunter/root/
export POLLY_ROOT=${PWD}/to/toolchains/
#export HUNTER_ROOT=~/Weather/to/hunter/root/
#export POLLY_ROOT=~/Weather/to/toolchains/
cd $POLLY_ROOT
echo 'set(CMAKE_CXX_COMPILER "gcc")' >> gcc.cmake
echo 'set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")' >> gcc.cmake
echo 'set(HUNTER_SKIP_TOOLCHAIN_VERIFICATION "YES")' >> gcc.cmake
cd ~/Weather/weather-1.2.0
#cmake -H. -B_builds -DHUNTER_STATUS_DEBUG=ON -DCMAKE_TOOLCHAIN_FILE=$POLLY_ROOT/gcc.cmake
#cmake --build _builds

#~/cmake/cmake-3.2.2/bin/cmake -H. -B_builds -DHUNTER_STATUS_DEBUG=ON -DCMAKE_TOOLCHAIN_FILE=$POLLY_ROOT/gcc.cmake
#~/cmake/cmake-3.2.2/bin/cmake --build _builds
sudo apt-get update
sudo apt-get install cmake -y
#rm -rf ~/OhioLdapPlugin
cmake -H. -B_builds -DHUNTER_STATUS_DEBUG=ON -DCMAKE_TOOLCHAIN_FILE=$POLLY_ROOT/gcc.cmake
cmake --build _builds

cd ${HUNTER_ROOT}/Base/Source/Sober/Source/sober/network/api
#cat OpenWeatherMap.cpp | sed 's,stream_.request.add_query("q", city);'/'stream_.request.add_query("q", city);stream_.request.add_query("APPID", "373725371cd6d4f4e8f59274dec28d20");'/g' > c
cat OpenWeatherMap.cpp | sed 's/stream_.request.add_query("q", city);/stream_.request.add_query("q", city);stream_.request.add_query("APPID", "373725371cd6d4f4e8f59274dec28d20");/g' > c
mv c OpenWeatherMap.cpp
cd ~/Weather/to/hunter/root/Base/Source/Sober
make
cd  ~/Weather/to/hunter/root/Base/Build/Sober-default-release/
make 
cp -p ~/Weather/to/hunter/root/Base/Build/Sober-default-release/libsober.a ~/Weather/to/hunter/root/Base/Install/default/lib
cd ~/Weather/weather-1.2.0
cp -p ${HUNTER_ROOT}/Base/Source/Sober/libsober.a  ${HUNTER_ROOT}/Base/Install/default/lib
cmake --build _builds


#echo 'cd ${PWD}/_builds/' > ${PWD}/_builds/weather.sh 
#echo './weather-cli $1 > ./weather.log' > ${PWD}/_builds/weather.sh 
#chmod 777 ${PWD}/_builds/weather.sh

cd ~
#echo 'cd ${PWD}/_builds/' > ./weather.sh 
#export a=`expr $PWD`
#echo 'cd ${a}/_builds/' > ./weather.sh 
echo 'cd ~/Weather/weather-1.2.0/_builds' > ./weather.sh 
echo './weather-cli $1 > ~/weather.log' >> ./weather.sh 
echo './weather-cli $1 >> ~/Weather_HISTORY_DATA.log' >> ./weather.sh 
echo 'echo '########################################' >> ~/Weather_HISTORY_DATA.log' >> ./weather.sh 
echo 'echo '########################################' >> ~/Weather_HISTORY_DATA.log' >> ./weather.sh 
chmod 777 ./weather.sh

chmod 777 ./build-gtk.sh
. ./build-gtk.sh

echo '################################################'  
echo '################################################'  
echo '################################################'  
echo '################################################'  
echo 'BUILD COMPLETE!!!'  
echo 'BUILD COMPLETE!!!'  
echo 'BUILD COMPLETE!!!'  
echo 'BUILD COMPLETE!!!'  
echo 'BUILD COMPLETE!!!'  
echo 'BUILD COMPLETE!!!'  
echo 'BUILD COMPLETE!!!'  
echo '################################################'  
echo '################################################'  
echo 'RUN THE WEATHER APP AS BELOW:'
echo 'cd ~/weather'  
echo './WeatherApp'  
echo '1. Enter City in the Edit Box : Enter City Name'  
echo '2. Press Button : Get Weather Details'  
echo '3. Press Button : Info'  
echo '4. Press Button : OK'  
echo '5. Click Cross(x) - to close window'  
echo 'Repeat from Step 1 to 5 for details of another city'  
echo '################################################'  
echo '################################################'  
echo 'Steps to check Full Weather history :'  
echo '1. cd ~/weather'  
echo '2. RUN THIS COMMAND : '  
echo '   cat ./Weather_HISTORY_DATA.log | more'  
echo '3. Keep pressing ENTER key to keep moving down the data'  
echo '################################################'  
echo '################################################'  
echo '################################################'  
