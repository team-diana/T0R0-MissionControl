all: update compile run

update:
	#git pull origin master

compile:
	echo "-> Compiling..."
	cd ${CURDIR}/build && cmake .. && make gui_missioncontrol

run:
	echo "-> Running..."
	cd ${CURDIR}/build/bin && ./gui_missioncontrol
