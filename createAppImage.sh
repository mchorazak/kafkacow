 #!/bin/bash
echo "THIS IS an AppImage creator"
cd ..
BASELONGNAME=$(pwd)
echo 'THIS IS **base long name'
echo "$BASELONGNAME"
DIR="$BASELONGNAME/kafkacow.AppDir/usr"
if [ -d $DIR ]; 
then
    printf '%s\n' "Overwriting directory($DIR)"
    rm -rf $DIR
fi
mkdir -p "$DIR";
cp -r "$BASELONGNAME/build/." "$DIR"
cd kafkacow.AppDir
curl -L https://github.com/probonopd/AppImageKit/releases/download/5/AppRun --output AppRun
chmod a+x AppRun
cd ..
curl -L https://github.com/probonopd/AppImageKit/releases/download/5/AppImageAssistant --output AppImageAssistant
chmod a+x AppImageAssistant

mv $BASELONGNAME/kafkacow/AppImageResources/kafkacow.desktop $BASELONGNAME/kafkacow.AppDir
mv $BASELONGNAME/kafkacow/AppImageResources/icon.png $BASELONGNAME/kafkacow.AppDir

if [ -f "$BASELONGNAME/kafkacow-image.AppImage" ];
then
    printf '%s\n' "Overwriting image..."
    rm -rf "$BASELONGNAME/kafkacow-image.AppImage"
fi


echo '.................current path:'
echo "$PWD"
ls
cd kafkacow.AppDir
echo '.................current path:'
echo "$PWD"
ls
cd usr
echo '.................current path:'
echo "$PWD"
ls
cd ..
cd ..

apt install fuse
modprobe fuse
groupadd fuse

./AppImageAssistant kafkacow.AppDir "./$1.AppImage"
