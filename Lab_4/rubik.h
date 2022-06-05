#ifndef RUBIK_RUBIK_H
#define RUBIK_RUBIK_H

#include <fstream>
#include <random>
#include <ctime>

static const char pString[6][3][3] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1, 1},
        {2, 2, 2, 2, 2, 2, 2, 2, 2},
        {3, 3, 3, 3, 3, 3, 3, 3, 3},
        {4, 4, 4, 4, 4, 4, 4, 4, 4},
        {5, 5, 5, 5, 5, 5, 5, 5, 5}
};
//развертка
/*   green  yel-w  blue
     4 4 4  0 0 0  5 5 5     0 1 2  0 1 2  0 1 2
     4 4 4  0 0 0  5 5 5     3 4 5  3 4 5  3 4 5
     4 4 4  0 0 0  5 5 5     6 7 8  6 7 8  6 7 8
           orange
            1 1 1                   0 1 2
            1 1 1                   3 4 5
            1 1 1                   6 7 8
            white
            2 2 2                   0 1 2
            2 2 2                   3 4 5
            2 2 2                   6 7 8
            red
            3 3 3                   0 1 2
            3 3 3                   3 4 5
            3 3 3                   6 7 8
 */

class Cube {
private:
    char sides[6][3][3] = {
            {0, 0, 0, 0, 0, 0, 0, 0, 0},
            {1, 1, 1, 1, 1, 1, 1, 1, 1},
            {2, 2, 2, 2, 2, 2, 2, 2, 2},
            {3, 3, 3, 3, 3, 3, 3, 3, 3},
            {4, 4, 4, 4, 4, 4, 4, 4, 4},
            {5, 5, 5, 5, 5, 5, 5, 5, 5}
    };

    bool CheckYellowCross() const {
        if (sides[0][0][1] == 0 && sides[0][1][0] == 0 && sides[0][1][2] == 0 && sides[0][2][1] == 0) {
            if (sides[1][0][1] == 1 && sides[3][2][1] == 3 && sides[4][1][2] == 4 && sides[5][1][0] == 5) {
                return true;
            }
        }
        return false;
    }

    bool IsRepeatYellowCross(std::vector<std::string> &solution) {
        bool flag = false;
        if (sides[2][0][1] == 0 && sides[1][2][1] == 1) {
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(1, solution);
            flag = true;
        }
        if (sides[2][2][1] == 0 && sides[3][0][1] == 3) {
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(3, solution);
            flag = true;
        }
        if (sides[2][1][2] == 0 && sides[5][1][2] == 5) {
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(5, solution);
            flag = true;
        }
        if (sides[2][1][0] == 0 && sides[4][1][0] == 4) {
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(4, solution);
            flag = true;
        }

        if (sides[2][0][1] == 1 && sides[1][2][1] == 0) {
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            RotationClockWise(1, solution);
            RotationClockWise(4, solution);
            flag = true;
        }
        if (sides[2][2][1] == 3 && sides[3][0][1] == 0) {
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(5, solution);
            RotationClockWise(3, solution);
            RotationClockWise(5, solution);
            flag = true;
        }
        if (sides[2][1][2] == 5 && sides[5][1][2] == 0) {
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(1, solution);
            RotationClockWise(5, solution);
            RotationClockWise(1, solution);
            flag = true;
        }
        if (sides[2][1][0] == 4 && sides[4][1][0] == 0) {
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            RotationClockWise(4, solution);
            RotationClockWise(3, solution);
            flag = true;
        }

        if (sides[1][1][0] == 0) {
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(1, solution);
            flag = true;
        }
        if (sides[3][1][2] == 0) {
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(3, solution);
            flag = true;
        }
        if (sides[4][0][1] == 0) {
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(4, solution);
            flag = true;
        }
        if (sides[5][2][1] == 0) {
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(5, solution);
            flag = true;
        }

        if (sides[1][1][2] == 0) {
            RotationClockWise(1, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(1, solution);
            flag = true;
        }
        if (sides[3][1][0] == 0) {
            RotationClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            flag = true;
        }
        if (sides[4][2][1] == 0) {
            RotationClockWise(4, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            flag = true;
        }
        if (sides[5][0][1] == 0) {
            RotationClockWise(5, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(5, solution);
            flag = true;
        }

        if (sides[1][0][1] == 0) {
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(1, solution);
            flag = true;
        }
        if (sides[3][2][1] == 0) {
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(3, solution);
            flag = true;
        }
        if (sides[4][1][2] == 0) {
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(4, solution);
            flag = true;
        }
        if (sides[5][1][0] == 0) {
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(5, solution);
            flag = true;
        }

        if (sides[0][0][1] == 0 && sides[3][2][1] != 3) {
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(3, solution);
            flag = true;
        }
        if (sides[0][1][0] == 0 && sides[4][1][2] != 4) {
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(4, solution);
            flag = true;
        }
        if (sides[0][2][1] == 0 && sides[1][0][1] != 1) {
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(1, solution);
            flag = true;
        }
        if (sides[0][1][2] == 0 && sides[5][1][0] != 5) {
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(5, solution);
            flag = true;
        }

        return flag;
    }

    void YellowCross(std::vector<std::string> &solution) {
        bool lastStatus = IsRepeatYellowCross(solution);
        if (CheckYellowCross()) return;
        RotationClockWise(2, solution);
        int iter_count = 1;
        for (; iter_count <= 4;) {
            bool curStatus = IsRepeatYellowCross(solution);
            if (lastStatus == curStatus && !curStatus) {
                ++iter_count;
                lastStatus = curStatus;
            } else {
                iter_count = 0;
                lastStatus = curStatus;
            }
            RotationClockWise(2, solution);
            if (CheckYellowCross()) break;
        }
    }

    bool CheckFirstLayer() const {
        bool res = true;
        if (CheckYellowCross()) {
            if (!(sides[0][2][2] == 0 && sides[1][0][2] == 1 && sides[5][2][0] == 5)) res = false;
            if (!(sides[0][2][0] == 0 && sides[1][0][0] == 1 && sides[4][2][2] == 4)) res = false;
            if (!(sides[0][0][0] == 0 && sides[4][0][2] == 4 && sides[3][2][0] == 3)) res = false;
            if (!(sides[0][0][2] == 0 && sides[3][2][2] == 3 && sides[5][0][0] == 5)) res = false;
        } else res = false;
        return res;
    }

    bool IsRepeatFirstLayer(std::vector<std::string> &solution) {
        bool flag = false;
        if (sides[1][2][0] == 0 && sides[2][0][0] == 1 && sides[4][2][0] == 4) {
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(1, solution);
            flag = true;
        }
        if (sides[5][2][2] == 0 && sides[1][2][2] == 1 && sides[2][0][2] == 5) {
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(5, solution);
            flag = true;
        }
        if (sides[4][0][0] == 0 && sides[3][0][0] == 3 && sides[2][2][0] == 4) {
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(4, solution);
            flag = true;
        }
        if (sides[3][0][2] == 0 && sides[2][2][2] == 3 && sides[5][0][2] == 5) {
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(3, solution);
            flag = true;
        }

        if (sides[1][2][0] == 1 && sides[2][0][0] == 4 && sides[4][2][0] == 0) {
            RotationClockWise(4, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            flag = true;

        }
        if (sides[5][2][2] == 5 && sides[1][2][2] == 0 && sides[2][0][2] == 1) {
            RotationClockWise(1, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(1, solution);
            flag = true;
        }
        if (sides[4][0][0] == 4 && sides[3][0][0] == 0 && sides[2][2][0] == 3) {
            RotationClockWise(3, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            flag = true;
        }
        if (sides[3][0][2] == 3 && sides[2][2][2] == 5 && sides[5][0][2] == 0) {
            RotationClockWise(5, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(5, solution);
            flag = true;
        }

        if (sides[1][2][0] == 4 && sides[2][0][0] == 0 && sides[4][2][0] == 1) {
            RotationClockWise(4, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(4, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            flag = true;
        }
        if (sides[5][2][2] == 1 && sides[1][2][2] == 5 && sides[2][0][2] == 0) {
            RotationClockWise(1, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(1, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(1, solution);
            flag = true;
        }
        if (sides[4][0][0] == 3 && sides[3][0][0] == 4 && sides[2][2][0] == 0) {
            RotationClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(3, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            flag = true;
        }
        if (sides[3][0][2] == 5 && sides[2][2][2] == 0 && sides[5][0][2] == 3) {
            RotationClockWise(5, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(5, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(5, solution);
            flag = true;
        }

        if (sides[1][0][0] == 0) {
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(1, solution);
            flag = true;
        }
        if (sides[3][2][2] == 0) {
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(3, solution);
            flag = true;
        }
        if (sides[4][0][2] == 0) {
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(4, solution);
            flag = true;
        }
        if (sides[5][2][0] == 0) {
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(5, solution);
            flag = true;
        }

        if (sides[1][0][2] == 0) {
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(5, solution);
            flag = true;
        }
        if (sides[3][2][0] == 0) {
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(4, solution);
            flag = true;
        }
        if (sides[4][2][2] == 0) {
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(1, solution);
            flag = true;
        }
        if (sides[5][0][0] == 0) {
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(3, solution);
            flag = true;
        }

        if (sides[0][2][2] == 0 && (sides[1][0][2] != 1 || sides[5][2][0] != 5)) {
            RotationClockWise(1, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(1, solution);
            flag = true;
        }
        if (sides[0][2][0] == 0 && (sides[1][0][0] != 1 || sides[4][2][2] != 4)) {
            RotationClockWise(4, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            flag = true;
        }
        if (sides[0][0][0] == 0 && (sides[4][0][2] != 4 || sides[3][2][0] != 3)) {
            RotationClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            flag = true;
        }
        if (sides[0][0][2] == 0 && (sides[3][2][2] != 3 || sides[5][0][0] != 5)) {
            RotationClockWise(5, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(5, solution);
            flag = true;
        }

        return flag;
    }

    void FirstLayer(std::vector<std::string> &solution) {
        if (!CheckYellowCross()) {
            throw std::logic_error("the yellow cross is not assembled");
        }
        bool lastStatus = IsRepeatFirstLayer(solution);
        if (CheckFirstLayer()) return;
        RotationClockWise(2, solution);
        int iter_count = 0;
        for (; iter_count < 4;) {
            bool curStatus = IsRepeatFirstLayer(solution);
            if (lastStatus == curStatus && !curStatus) {
                ++iter_count;
                lastStatus = curStatus;
            } else {
                iter_count = 0;
                lastStatus = curStatus;
            }
            RotationClockWise(2, solution);
            if (CheckFirstLayer()) break;
        }
    }

    bool CheckTwoLayer() const {
        bool res = true;
        if (CheckFirstLayer()) {
            if (sides[1][1][0] != 1 || sides[1][1][2] != 1) res = false;
            if (sides[3][1][0] != 3 || sides[3][1][2] != 3) res = false;
            if (sides[4][0][1] != 4 || sides[4][2][1] != 4) res = false;
            if (sides[5][0][1] != 5 || sides[5][2][1] != 5) res = false;
        } else res = false;
        return res;
    }

    bool IsRepeatTwoLayer(std::vector<std::string> &solution) {
        bool flag = false;

        if (sides[1][2][1] == 1 && sides[2][0][1] == 4) {
            RotationClockWise(2, solution);
            RotationClockWise(4, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(1, solution);
            RotationClockWise(2, solution);
            RotationClockWise(1, solution);
            flag = true;
        }
        if (sides[3][0][1] == 3 && sides[2][2][1] == 5) {
            RotationClockWise(2, solution);
            RotationClockWise(5, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            RotationClockWise(2, solution);
            RotationClockWise(3, solution);
            flag = true;
        }
        if (sides[4][1][0] == 4 && sides[2][1][0] == 3) {
            RotationClockWise(2, solution);
            RotationClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            RotationClockWise(2, solution);
            RotationClockWise(4, solution);
            flag = true;
        }
        if (sides[5][1][2] == 5 && sides[2][1][2] == 1) {
            RotationClockWise(2, solution);
            RotationClockWise(1, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(5, solution);
            RotationClockWise(2, solution);
            RotationClockWise(5, solution);
            flag = true;
        }

        if (sides[1][2][1] == 1 && sides[2][0][1] == 5) {
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(5, solution);
            RotationClockWise(2, solution);
            RotationClockWise(5, solution);
            RotationClockWise(2, solution);
            RotationClockWise(1, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(1, solution);
            flag = true;
        }
        if (sides[3][0][1] == 3 && sides[2][2][1] == 4) {
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            RotationClockWise(2, solution);
            RotationClockWise(4, solution);
            RotationClockWise(2, solution);
            RotationClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            flag = true;
        }
        if (sides[4][1][0] == 4 && sides[2][1][0] == 1) {
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(1, solution);
            RotationClockWise(2, solution);
            RotationClockWise(1, solution);
            RotationClockWise(2, solution);
            RotationClockWise(4, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            flag = true;
        }
        if (sides[5][1][2] == 5 && sides[2][1][2] == 3) {
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            RotationClockWise(2, solution);
            RotationClockWise(3, solution);
            RotationClockWise(2, solution);
            RotationClockWise(5, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(5, solution);
            flag = true;

        }

        return flag;
    }

    void TwoLayers(std::vector<std::string> &solution) {
        if (!CheckFirstLayer()) {
            throw std::logic_error("first layer is not assembled");
        }
        while (!CheckTwoLayer()) {
            bool lastStatus = IsRepeatTwoLayer(solution);
            RotationClockWise(2, solution);
            int iter_count = 0;
            for (; iter_count < 4;) {
                bool curStatus = IsRepeatTwoLayer(solution);
                if (lastStatus == curStatus && !curStatus) {
                    ++iter_count;
                    lastStatus = curStatus;
                } else {
                    iter_count = 0;
                    lastStatus = curStatus;
                }
                RotationClockWise(2, solution);
                if (CheckTwoLayer()) break;
            }
            if (sides[1][1][2] != 1 || sides[5][2][1] != 5) {
                RotationClockWise(2, solution);
                RotationClockWise(1, solution);
                RotationCounterClockWise(2, solution);
                RotationCounterClockWise(1, solution);
                RotationCounterClockWise(2, solution);
                RotationCounterClockWise(5, solution);
                RotationClockWise(2, solution);
                RotationClockWise(5, solution);
            }
            if (sides[3][1][0] != 3 || sides[4][0][1] != 4) {
                RotationClockWise(2, solution);
                RotationClockWise(3, solution);
                RotationCounterClockWise(2, solution);
                RotationCounterClockWise(3, solution);
                RotationCounterClockWise(2, solution);
                RotationCounterClockWise(4, solution);
                RotationClockWise(2, solution);
                RotationClockWise(4, solution);
            }
            if (sides[4][2][1] != 4 || sides[1][1][0] != 1) {
                RotationClockWise(2, solution);
                RotationClockWise(4, solution);
                RotationCounterClockWise(2, solution);
                RotationCounterClockWise(4, solution);
                RotationCounterClockWise(2, solution);
                RotationCounterClockWise(1, solution);
                RotationClockWise(2, solution);
                RotationClockWise(1, solution);
            }
            if (sides[5][0][1] != 5 || sides[3][1][2] != 3) {
                RotationClockWise(2, solution);
                RotationClockWise(5, solution);
                RotationCounterClockWise(2, solution);
                RotationCounterClockWise(5, solution);
                RotationCounterClockWise(2, solution);
                RotationCounterClockWise(3, solution);
                RotationClockWise(2, solution);
                RotationClockWise(3, solution);
            }
            if (CheckTwoLayer()) break;
        }


    }

    bool CheckIsThirdLayerCross() const {
        if (CheckTwoLayer()) {
            if (sides[2][0][1] == 2 && sides[2][1][0] == 2 && sides[2][1][2] == 2 && sides[2][2][1] == 2) {
                return true;
            }
        }
        return false;
    }

    void ThirdLayerCross(std::vector<std::string> &solution) {
        if (!CheckTwoLayer()) {
            throw std::logic_error("two layer is not assembled");
        }
        if (CheckIsThirdLayerCross()) return;

        if (sides[2][0][1] != 2 && sides[2][1][0] != 2 && sides[2][1][2] != 2 && sides[2][2][1] != 2) {
            RotationClockWise(3, solution);
            RotationClockWise(2, solution);
            RotationClockWise(5, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(3, solution);
            RotationClockWise(5, solution);
            RotationClockWise(1, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(5, solution);
        } else if (sides[2][0][1] == 2 && sides[2][1][2] == 2) {
            RotationClockWise(4, solution);
            RotationClockWise(2, solution);
            RotationClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(4, solution);
        } else if (sides[2][1][2] == 2 && sides[2][2][1] == 2) {
            RotationClockWise(1, solution);
            RotationClockWise(2, solution);
            RotationClockWise(4, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(1, solution);
        } else if (sides[2][2][1] == 2 && sides[2][1][0] == 2) {
            RotationClockWise(5, solution);
            RotationClockWise(2, solution);
            RotationClockWise(1, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(5, solution);
        } else if (sides[2][0][1] == 2 && sides[2][1][0] == 2) {
            RotationClockWise(3, solution);
            RotationClockWise(2, solution);
            RotationClockWise(5, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(3, solution);
        } else if (sides[2][0][1] == 2 && sides[2][2][1] == 2) {
            RotationClockWise(4, solution);
            RotationClockWise(3, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(4, solution);

        } else if (sides[2][1][0] == 2 && sides[2][1][2] == 2) {
            RotationClockWise(1, solution);
            RotationClockWise(4, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(1, solution);
        }

    }

    bool CheckIsThirdLayerCrossRight() const {
        if (CheckIsThirdLayerCross()) {
            if (sides[1][2][1] == 1 && sides[3][0][1] == 3 && sides[4][1][0] == 4 &&
                sides[5][1][2] == 5) {
                return true;
            }
        }
        return false;
    }

    void ThirdLayerCrossRight(std::vector<std::string> &solution) {
        if (!CheckIsThirdLayerCross()) {
            throw std::logic_error("third layer cross is not assembled");
        }
        if (CheckIsThirdLayerCrossRight()) return;

        if (sides[5][1][2] == 1) {
            RotationClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(3, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            RotationClockWise(2, solution);
            RotationClockWise(3, solution);
        } else if (sides[3][0][1] == 1) {
            RotationClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(4, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            RotationClockWise(2, solution);
            RotationClockWise(4, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(3, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            RotationClockWise(2, solution);
            RotationClockWise(3, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(4, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            RotationClockWise(2, solution);
            RotationClockWise(4, solution);
        } else if (sides[4][1][0] == 1) {
            RotationClockWise(2, solution);
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(5, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(5, solution);
            RotationClockWise(2, solution);
            RotationClockWise(5, solution);
        }

        if (sides[3][0][1] == 4) {
            RotationClockWise(2, solution);
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(1, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(1, solution);
            RotationClockWise(2, solution);
            RotationClockWise(1, solution);
        }
        if (sides[5][1][2] == 4) {
            RotationClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(3, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            RotationClockWise(2, solution);
            RotationClockWise(3, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(5, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(5, solution);
            RotationClockWise(2, solution);
            RotationClockWise(5, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(3, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(3, solution);
            RotationClockWise(2, solution);
            RotationClockWise(3, solution);

        }
        if (sides[5][1][2] == 3) {
            RotationClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(2, solution);
            RotationCounterClockWise(2, solution);
            RotationClockWise(4, solution);
            RotationClockWise(2, solution);
            RotationCounterClockWise(4, solution);
            RotationClockWise(2, solution);
            RotationClockWise(4, solution);
        }

        if (!CheckIsThirdLayerCrossRight()) {
            throw std::logic_error("third layer right cross is not assembled");
        }


    }

    bool CheckThirdLayerRightCorners() {
        if (CheckIsThirdLayerCrossRight()) {
            bool flag = true;
            if (sides[1][2][0] + sides[2][0][0] + sides[4][2][0] != 7) flag = false;
            if (sides[1][2][2] + sides[2][0][2] + sides[5][2][2] != 8) flag = false;
            if (sides[3][0][0] + sides[2][2][0] + sides[4][0][0] != 9) flag = false;
            if (sides[3][0][2] + sides[2][2][2] + sides[5][0][2] != 10) flag = false;
            return flag;
        }
        return false;
    }

    void ThirdLayerRightCorners(std::vector<std::string> &solution) {
        if (!CheckIsThirdLayerCrossRight()) {
            throw std::logic_error("third layer cross right is not assembled");
        }

        if (CheckThirdLayerRightCorners()) return;
        if (sides[1][2][2] + sides[2][0][2] + sides[5][2][2] == 7) {
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(5, solution);
            RotationClockWise(1, solution);
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(1, solution);
            RotationClockWise(5, solution);
            RotationClockWise(1, solution);
            RotationClockWise(4, solution);
        } else if (sides[3][0][0] + sides[2][2][0] + sides[4][0][0] == 7) {
            RotationCounterClockWise(4, solution);
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(5, solution);
            RotationClockWise(1, solution);
            RotationClockWise(4, solution);
            RotationCounterClockWise(1, solution);
            RotationClockWise(5, solution);
            RotationClockWise(1, solution);
        } else if (sides[3][0][2] + sides[2][2][2] + sides[5][0][2] == 7) {
            RotationCounterClockWise(1, solution);
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(3, solution);
            RotationClockWise(5, solution);
            RotationClockWise(1, solution);
            RotationCounterClockWise(5, solution);
            RotationClockWise(3, solution);
            RotationClockWise(5, solution);
        }

        if (sides[3][0][2] + sides[2][2][2] + sides[5][0][2] == 9) {
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(4, solution);
            RotationClockWise(3, solution);
            RotationClockWise(5, solution);
            RotationCounterClockWise(3, solution);
            RotationClockWise(4, solution);
            RotationClockWise(3, solution);
        }
        if (sides[1][2][2] + sides[2][0][2] + sides[5][2][2] == 9) {
            RotationCounterClockWise(3, solution);
            RotationCounterClockWise(4, solution);
            RotationClockWise(3, solution);
            RotationCounterClockWise(5, solution);
            RotationCounterClockWise(3, solution);
            RotationClockWise(4, solution);
            RotationClockWise(3, solution);
            RotationClockWise(5, solution);
        }

        if (!CheckThirdLayerRightCorners()) {
            throw std::logic_error("third layer right corners is not assembled");
        }
    }

    void ThirdLayerRight(std::vector<std::string> &solution) {
        if (!CheckThirdLayerRightCorners()) {
            throw std::logic_error("third layer corners right is not assembled");
        }

        if (Status()) return;

        for (int i = 0; i < 4; ++i) {
            if (sides[4][2][0] == 2) {
                RotationCounterClockWise(1, solution);
                RotationClockWise(4, solution);
                RotationClockWise(1, solution);
                RotationCounterClockWise(4, solution);
                RotationCounterClockWise(1, solution);
                RotationClockWise(4, solution);
                RotationClockWise(1, solution);
                RotationCounterClockWise(4, solution);
            } else if (sides[1][2][0] == 2) {
                RotationClockWise(4, solution);
                RotationCounterClockWise(1, solution);
                RotationCounterClockWise(4, solution);
                RotationClockWise(1, solution);
                RotationClockWise(4, solution);
                RotationCounterClockWise(1, solution);
                RotationCounterClockWise(4, solution);
                RotationClockWise(1, solution);
            }
            RotationClockWise(2, solution);
        }

        for (int i = 0; i < 4; ++i) {
            if (Status()) {
                return;
            }
        }

        throw std::logic_error("the invariant is violated");

    }

public:

//поворот против часовой стрелки
    void RotationCounterClockWise(char side, std::vector<std::string> &solution, int direction = 1) {
        //провернули данную грань
        for (int x = 0; x < 1; x++) {
            for (int y = x; y < 2 - x; y++) {
                char temp = sides[side][x][y];
                sides[side][x][y] = sides[side][y][2 - x];
                sides[side][y][2 - x] = sides[side][2 - x][2 - y];
                sides[side][2 - x][2 - y] = sides[side][2 - y][x];
                sides[side][2 - y][x] = temp;
            }
        }
        //проворот остальных граней
        char tmp;
        switch (side) {
            case 0: {
                //left point
                tmp = sides[1][0][0];
                sides[1][0][0] = sides[4][0][2];
                sides[4][0][2] = sides[3][2][2];
                sides[3][2][2] = sides[5][2][0];
                sides[5][2][0] = tmp;
                //middle point
                tmp = sides[1][0][1];
                sides[1][0][1] = sides[4][1][2];
                sides[4][1][2] = sides[3][2][1];
                sides[3][2][1] = sides[5][1][0];
                sides[5][1][0] = tmp;
                //right point
                tmp = sides[1][0][2];
                sides[1][0][2] = sides[4][2][2];
                sides[4][2][2] = sides[3][2][0];
                sides[3][2][0] = sides[5][0][0];
                sides[5][0][0] = tmp;
/*                for (int i = 0; i < 6; ++i) {
                    std::cout << "!!!!!!!!!!!!!!! " << i << "\n";
                    for (int j = 0; j < 3; ++j) {
                        for (int k = 0; k < 3; ++k) {
                            std::cout << (int) sides[i][j][k] << " ";
                        }
                        std::cout << "\n";
                    }
                    std::cout << "\n";
                }*/
            }
                break;
            case 1: {
                //left point
                tmp = sides[2][0][0];
                sides[2][0][0] = sides[4][2][2];
                sides[4][2][2] = sides[0][2][2];
                sides[0][2][2] = sides[5][2][2];
                sides[5][2][2] = tmp;
                //middle point
                tmp = sides[2][0][1];
                sides[2][0][1] = sides[4][2][1];
                sides[4][2][1] = sides[0][2][1];
                sides[0][2][1] = sides[5][2][1];
                sides[5][2][1] = tmp;
                //right point
                tmp = sides[2][0][2];
                sides[2][0][2] = sides[4][2][0];
                sides[4][2][0] = sides[0][2][0];
                sides[0][2][0] = sides[5][2][0];
                sides[5][2][0] = tmp;
/*                for (int i = 0; i < 6; ++i) {
                    std::cout << "!!!!!!!!!!!!!!! " << i << "\n";
                    for (int j = 0; j < 3; ++j) {
                        for (int k = 0; k < 3; ++k) {
                            std::cout << (int) sides[i][j][k] << " ";
                        }
                        std::cout << "\n";
                    }
                    std::cout << "\n";
                }*/
            }
                break;
            case 2: {
                //left point
                tmp = sides[3][0][0];
                sides[3][0][0] = sides[4][2][0];
                sides[4][2][0] = sides[1][2][2];
                sides[1][2][2] = sides[5][0][2];
                sides[5][0][2] = tmp;
                //middle point
                tmp = sides[3][0][1];
                sides[3][0][1] = sides[4][1][0];
                sides[4][1][0] = sides[1][2][1];
                sides[1][2][1] = sides[5][1][2];
                sides[5][1][2] = tmp;
                //right point
                tmp = sides[3][0][2];
                sides[3][0][2] = sides[4][0][0];
                sides[4][0][0] = sides[1][2][0];
                sides[1][2][0] = sides[5][2][2];
                sides[5][2][2] = tmp;
/*                for (int i = 0; i < 6; ++i) {
                    std::cout << "!!!!!!!!!!!!!!! " << i << "\n";
                    for (int j = 0; j < 3; ++j) {
                        for (int k = 0; k < 3; ++k) {
                            std::cout << (int) sides[i][j][k] << " ";
                        }
                        std::cout << "\n";
                    }
                    std::cout << "\n";
                }*/
            }
                break;
            case 3: {
                //left point
                tmp = sides[0][0][0];
                sides[0][0][0] = sides[4][0][0];
                sides[4][0][0] = sides[2][2][2];
                sides[2][2][2] = sides[5][0][0];
                sides[5][0][0] = tmp;
                //middle point
                tmp = sides[0][0][1];
                sides[0][0][1] = sides[4][0][1];
                sides[4][0][1] = sides[2][2][1];
                sides[2][2][1] = sides[5][0][1];
                sides[5][0][1] = tmp;
                //right point
                tmp = sides[0][0][2];
                sides[0][0][2] = sides[4][0][2];
                sides[4][0][2] = sides[2][2][0];
                sides[2][2][0] = sides[5][0][2];
                sides[5][0][2] = tmp;
/*                for (int i = 0; i < 6; ++i) {
                    std::cout << "!!!!!!!!!!!!!!! " << i << "\n";
                    for (int j = 0; j < 3; ++j) {
                        for (int k = 0; k < 3; ++k) {
                            std::cout << (int) sides[i][j][k] << " ";
                        }
                        std::cout << "\n";
                    }
                    std::cout << "\n";
                }*/
            }
                break;
            case 4: {
                //left point
                tmp = sides[0][2][0];
                sides[0][2][0] = sides[1][2][0];
                sides[1][2][0] = sides[2][2][0];
                sides[2][2][0] = sides[3][2][0];
                sides[3][2][0] = tmp;
                //middle point
                tmp = sides[0][1][0];
                sides[0][1][0] = sides[1][1][0];
                sides[1][1][0] = sides[2][1][0];
                sides[2][1][0] = sides[3][1][0];
                sides[3][1][0] = tmp;
                //right point
                tmp = sides[0][0][0];
                sides[0][0][0] = sides[1][0][0];
                sides[1][0][0] = sides[2][0][0];
                sides[2][0][0] = sides[3][0][0];
                sides[3][0][0] = tmp;
/*                for (int i = 0; i < 6; ++i) {
                    std::cout << "!!!!!!!!!!!!!!! " << i << "\n";
                    for (int j = 0; j < 3; ++j) {
                        for (int k = 0; k < 3; ++k) {
                            std::cout << (int) sides[i][j][k] << " ";
                        }
                        std::cout << "\n";
                    }
                    std::cout << "\n";
                }*/
            }
                break;
            case 5: {
                //left point
                tmp = sides[0][0][2];
                sides[0][0][2] = sides[3][0][2];
                sides[3][0][2] = sides[2][0][2];
                sides[2][0][2] = sides[1][0][2];
                sides[1][0][2] = tmp;
                //middle point
                tmp = sides[0][1][2];
                sides[0][1][2] = sides[3][1][2];
                sides[3][1][2] = sides[2][1][2];
                sides[2][1][2] = sides[1][1][2];
                sides[1][1][2] = tmp;
                //right point
                tmp = sides[0][2][2];
                sides[0][2][2] = sides[3][2][2];
                sides[3][2][2] = sides[2][2][2];
                sides[2][2][2] = sides[1][2][2];
                sides[1][2][2] = tmp;
/*                for (int i = 0; i < 6; ++i) {
                    std::cout << "!!!!!!!!!!!!!!! " << i << "\n";
                    for (int j = 0; j < 3; ++j) {
                        for (int k = 0; k < 3; ++k) {
                            std::cout << (int) sides[i][j][k] << " ";
                        }
                        std::cout << "\n";
                    }
                    std::cout << "\n";
                }*/
            }
                break;
            default:
                throw std::overflow_error("cube has only 6 sides");
        }
        if (direction) {
            solution.push_back(std::to_string(side) + "' ");
        }
    }

//поворот по часовой стрелке
    void RotationClockWise(char side, std::vector<std::string> &solution, int direction = 0) {
        RotationCounterClockWise(side, solution, 0);
        RotationCounterClockWise(side, solution, 0);
        RotationCounterClockWise(side, solution, 0);
        solution.push_back(std::to_string(side) + " ");
    }

    friend std::ostream &operator<<(std::ostream &out, Cube cube) {
        for (int i = 0; i < 6; ++i) {
            std::cout << "!!!!!!!!!!!!!!! " << i << "\n";
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    std::cout << (int) cube.sides[i][j][k] << " ";
                }
                std::cout << "\n";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
        return out;
    }

    void Generation() {
        srand(time(0));
        std::vector<std::string> solution;
        std::random_device randomDevice;
        std::mt19937 Generator(randomDevice());
        std::uniform_int_distribution<> cnt(1, 20);
        int rotation_count = cnt(Generator);
        std::cout << "rotation count = " << rotation_count << "\n";
        for (int i = 0; i < rotation_count; ++i) {
            std::uniform_int_distribution<> rot_side(0, 5);
            char rotation_side = rot_side(Generator);
            std::uniform_int_distribution<> rot_dir(0, 1);
            char rotation_direction = rot_dir(Generator);
            if (rotation_direction == 0) {
                RotationClockWise(rotation_side, solution);
            } else {
                RotationCounterClockWise(rotation_side, solution);
            }
        }
        for (auto &i: solution) {
            std::cout << i;
        }
        std::cout << "\n";
    }

    [[maybe_unused]] void InputFile(const char *file_name) {
        std::string line;
        std::ifstream file(file_name); // окрываем файл для чтения
        if (file.is_open()) {
            for (auto &side: sides) {
                for (auto &j: side) {
                    getline(file, line);
                    j[0] = line[0];
                    j[1] = line[2];
                    j[2] = line[4];
                }
                getline(file, line);
            }
            for (int k = 0; k < 6; ++k) {
                for (int i = 0; i < 3; ++i) {
                    for (int j = 0; j < 3; ++j) {
                        if (sides[k][i][j] == 'Y') sides[k][i][j] = 0;
                        if (sides[k][i][j] == 'O') sides[k][i][j] = 1;
                        if (sides[k][i][j] == 'W') sides[k][i][j] = 2;
                        if (sides[k][i][j] == 'R') sides[k][i][j] = 3;
                        if (sides[k][i][j] == 'G') sides[k][i][j] = 4;
                        if (sides[k][i][j] == 'B') sides[k][i][j] = 5;
                    }
                }
            }
        } else {
            throw std::runtime_error("Exception opening/reading file");
        }
        file.close();
    }

    [[maybe_unused]] void OutputFile(const char *file_name) {
        std::string line;
        std::ofstream file;
        file.open(file_name); // окрываем файл для чтения
        if (file.is_open()) {
            for (auto &side: sides) {
                for (auto &j: side) {
                    for (char k: j) {
                        file << (int) k << " ";
                    }
                    file << "\n";
                }
                file << "\n";
            }
        } else {
            throw std::runtime_error("Exception opening/reading file");
        }
        file.close();
    }

    [[nodiscard]] bool Status() const {
        bool flag = true;
        for (int k = 0; k < 6; ++k) {
            for (int i = 0; i < 3; ++i) {
                for (int j = 0; j < 3; ++j) {
                    if (pString[k][i][j] != sides[k][i][j]) {
                        flag = false;
                        return flag;
                    }
                }
            }
        }
        return flag;
    }

    void FindSolution() {
        std::vector<std::string> sol_1;
        YellowCross(sol_1);
        std::cout << "yellow cross finished:\n";
        for (auto &i: sol_1) {
            std::cout << i;
        }
        OutputFile("output1.txt");

        std::vector<std::string> sol_2;
        FirstLayer(sol_2);
        std::cout << "\nfirst layer finished:\n";
        for (auto &i: sol_2) {
            std::cout << i;
        }
        OutputFile("output2.txt");
        CheckFirstLayer();

        std::vector<std::string> sol_3;
        TwoLayers(sol_3);
        std::cout << "\ntwo layer finished:\n";
        for (auto &i: sol_3) {
            std::cout << i;
        }
        OutputFile("output3.txt");
        CheckTwoLayer();

        std::vector<std::string> sol_4;
        ThirdLayerCross(sol_4);
        std::cout << "\nthird layer cross finished:\n";
        for (auto &i: sol_4) {
            std::cout << i;
        }
        OutputFile("output4.txt");
        CheckIsThirdLayerCross();

        std::vector<std::string> sol_5;
        ThirdLayerCrossRight(sol_5);
        std::cout << "\nthird layer right cross finished:\n";
        for (auto &i: sol_5) {
            std::cout << i;
        }
        OutputFile("output5.txt");
        CheckIsThirdLayerCrossRight();

        std::vector<std::string> sol_6;
        ThirdLayerRightCorners(sol_6);
        std::cout << "\nthird layer right corners finished:\n";
        for (auto &i: sol_6) {
            std::cout << i;
        }
        OutputFile("output6.txt");
        CheckThirdLayerRightCorners();

        std::vector<std::string> sol_7;
        ThirdLayerRight(sol_7);
        std::cout << "\nLast layer finished:\n";
        for (auto &i: sol_7) {
            std::cout << i;
        }
        OutputFile("output7.txt");
        if (!Status()) throw std::logic_error("the invariant is violated");
    }

    void InputRotation(const std::string& steps) {
        for (int i = 0; i < steps.length();) {
            char rot_side = steps[i] - 48;
            char rot_direction = (steps[i + 1] == ' ' ? 0 : 1);
            std::vector<std::string> sol;
            if (rot_direction == 0) {
                RotationClockWise(rot_side, sol);
                i += 2;
            } else {
                RotationCounterClockWise(rot_side, sol);
                i += 3;
            }
        }
    }


};


#endif //RUBIK_RUBIK_H
