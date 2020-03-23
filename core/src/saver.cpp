#include "../saver.hpp"
#include <fstream>



void Saver::save(RectGrid grid)
{
    std::ofstream out;
    cout << "Saving results ..." << endl;
    out.open("output.vtk");
    out << "# vtk DataFile Version 3.0" << endl;
    out << "Created by StructuredVTKSaver::saveRectGrid << endl";
    out << "ASCII" << endl;
    out << "DATASET STRUCTURED_POINTS" << endl;
    out << "DIMENSIONS " << grid.getNx() << " " << grid.getNy() << "1" << endl;
    out << "SPACING " << grid.getDx() << " " << grid.getDy() << "1" << endl;
    out << "ORIGIN " << grid.getOx() << " " << grid.getOy() << "1" << endl;
    out << "POINT_DATA " << grid.getNx() * grid.getNy() << endl;
    out << "SCALARS vx float 1" << endl;
    out << "LOOKUP_TABLE vx_table" << endl;
    for (int i = 0; i < grid.getNx(); i++)
    {
        for (int q = 0; q < grid.getNy(); q++)
        {
            out << grid.getPressure(i, q);
        }
        out << endl;
    }
}
