/* +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
   Copyright (c) 2012-2014 The plumed team
   (see the PEOPLE file at the root of the distribution for a list of names)

   See http://www.plumed-code.org for more information.

   This file is part of plumed, version 2.

   plumed is free software: you can redistribute it and/or modify
   it under the terms of the GNU Lesser General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   plumed is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public License
   along with plumed.  If not, see <http://www.gnu.org/licenses/>.
+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++ */
#ifndef __PLUMED_analysis_DataCollectionObject_h
#define __PLUMED_analysis_DataCollectionObject_h

#include <map>
#include <vector>
#include "tools/Vector.h"
#include "tools/AtomNumber.h"

namespace PLMD {

class PDB;

namespace analysis {

class DataCollectionObject {
friend class ReadAnalysisFrames;
private:
/// The list of atom numbers that are stored in the object
  std::vector<AtomNumber> indices;
/// The list of atomic positions
  std::vector<Vector> positions;
/// The map containing the arguments that we are storing
  std::map<std::string,double> args;
public:
/// Set the names and atom numbers
  void setAtomNumbersAndArgumentNames( const std::vector<AtomNumber>& ind, const std::vector<std::string>& arg_names );
/// Set the positions of all the atoms
  void setAtomPositions( const std::vector<Vector>& pos );
/// Set the value of one of the arguments
  void setArgument( const std::string& name, const double& value );
/// Return one of the atomic positions
  Vector getAtomPosition( const AtomNumber& ind ) const ;
/// Get the value of one of the arguments
  double getArgumentValue( const std::string& name ) const ;
/// Transfer the data inside the object to a PDB object
  bool transferDataToPDB( PDB& mypdb );
};

inline
Vector DataCollectionObject::getAtomPosition( const AtomNumber& ind ) const {
  return positions[ind.index()];
}

inline
double DataCollectionObject::getArgumentValue( const std::string& name ) const {
  return args.find(name)->second;
}

}
}

#endif
