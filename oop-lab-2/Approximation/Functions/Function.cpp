#include "Function.h"

vector<double> Function::getKoefs()
{
    return koefs;
}

Function::Function(vector<double> koefs):koefs(koefs)
{

}

Function::~Function()
{

}
