all: update compile run

update:
	#git pull origin master

compile:
	cd ${CURDIR}/build && cmake .. && make gui_missioncontrol

run:
	cd ${CURDIR}/build/bin && ./gui_missioncontrol
