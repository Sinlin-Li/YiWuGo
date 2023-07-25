#include "SGFExporter.h"


SGFExporter::SGFExporter(int boardSize, float komi) : boardSize(boardSize), komi(komi) {
    sgfFile.open("output.sgf");
    sgfFile << "(;GM[1]FF[4]SZ[" << boardSize << "]KM[" << komi << "]";
}

void SGFExporter::exportMove(pii stone, Player player) {
    sgfFile << ";" << getColorString(player) << "[" << getCoordinateString(stone) << "]";
}

void SGFExporter::close() {
    sgfFile << ")";
    sgfFile.close();
}


string SGFExporter::getColorString(Player player) {
    return (player == BLACK) ? "B" : "W";
}

string SGFExporter::getCoordinateString(pii stone) {
    int y = stone.first;   //�����ƺ�Ҫ��һ��
    int x = stone.second;
    char letter = 'a' + x;
    char number = 'a' + y;
    return { letter, number };
}