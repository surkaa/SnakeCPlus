#pragma once
#ifndef _DREW_H

#include"snake.h"

#define screenWidth			(2 * DrewStartPoint_x + pmapW * cellWidth)
#define screenHigh			(2 * DrewStartPoint_y + pmapH * cellWidth)
#define outputMessageA_x	(3 * screenWidth / 10)
#define outputMessageB_x	(7 * screenWidth / 10)
#define outputMessage__x    ((outputMessageA_x + outputMessageB_x) / 2) - 120
#define outputMessageAB_y	(4 * DrewStartPoint_y / 5)
#define MessageWidth		(cellWidth)
#define MapBorderA_x		(DrewStartPoint_x + cellWidth)
#define MapBorderA_y		(DrewStartPoint_y + cellWidth)
#define MapBorderB_x		(MapBorderA_x + mapWidth * cellWidth - cellGap)
#define MapBorderB_y		(MapBorderA_y + mapHigh * cellWidth - cellGap)




#endif // !_DREW_H
