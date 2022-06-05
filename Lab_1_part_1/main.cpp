#include "geometry.h"

int main() {
    std::cout << "\n\n";

    const Point A(1.5, 2.5), B(0, 4), C(2, 12), D(4, 16), E(10, 18), F(30, 30);
    Polyline ABCDE{A, B, C, D, E};
    std::cout << "ABCDE perimeter = " << ABCDE.perimeter() << "\n";

    Close_polyline closed_ABCDE{A, B, C, D, E};
    std::cout << "closed_ABCDE perimeter = " << closed_ABCDE.perimeter() << "\n";

    std::cout << "!!!!!!!!!!!!!!!" << closed_ABCDE.get_count() << "\n";


    std::cout << "\n\n";

    Polygon ABCDEF{A, B, C, D, E, F};
    std::cout << "ABCDEF square = " << ABCDEF.square() << "\n";

    std::cout << "\n\n";

    Triangle ABC{A, B, C};
    std::cout << "ABC square = " << ABC.square() << "\n";
    std::cout << "ABC perimeter = " << ABC.perimeter() << "\n";

    std::cout << "\n\n";

    /*  Point G(-24,10),H(-18,16),I(-24,14),J(-22,16);
      Trapezoid GHJI{G,H,J,I};
      std::cout << "Object is trapezoid - " << " perimeter: " << GHJI.perimeter() << " square: " << GHJI.square() << "\n";

      std::cout << "\n\n";
      Point M(-34,22),O(-39.1962,19),P(-39.1962,13),L(-34,10),Q(-28.8038,13),N(-28.8038,19);
      Regular_polygon MOPLQN{M,O,P,L,Q,N};
      std::cout << "Regular polygon square = " << MOPLQN.square() << "\n";
      std::cout << "Regular polygon perimeter = " << MOPLQN.perimeter() << "\n";*/
}

