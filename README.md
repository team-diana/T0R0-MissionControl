# T0-R0 Mission Control GUI
A GUI to display all most vital data from T0-R0 rover

## Dependencies
### Mosquitto - MQTT Broker
#### Install
```bash
sudo apt install mosquitto
```
#### Launch
```bash
mosquitto
```

or in **verbose mode**
```bash
mosquitto -v
```

### MQTT for Qt
For the moment MQTT library for Qt is in a experimental stage and it doesn't come with Qt Creator (v5.11.1).
To install this library follow the instructions.

If you have version v5.11.1 of Qt Creator.

Launch
```bash
~/Qt/5.11.1/gcc_64/bin/qmake -query QT_INSTALL_LIBS
```
to locate the library folder and
```bash
cd <directory-from-the-output-of-previous-command>
```
substitute <> with the correct path.
*Probably it will look like something as ~/Qt/5.11.1/gcc_64/lib*

Clone the library repository with
```bash
git clone http://code.qt.io/qt/qtmqtt.git
```

Compile the library
```bash
cd qtmqtt
~/Qt/5.11.1/gcc_64/bin/qmake
make
sudo make install
```
*Probably you have to insert your system password*

**NOTE for Mac User**
Even thought this software isn't tested for Mac environment, you could try it by substituting `gcc_64` with `clang_64` in every commands above.

## Compile and Run
Directly inside of QtCreator
