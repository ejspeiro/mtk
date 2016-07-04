/*!
\file mtk_interp_1d_test.cc

\brief Testing the 1D interpolation.

\author: Eduardo J. Sanchez (ejspeiro) - esanchez at mail dot sdsu dot edu

\author: Johnny Corbino - jcorbino at mail dot sdsu dot edu
*/
/*
Copyright (C) 2016, Computational Science Research Center, San Diego State
University. All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
are permitted provided that the following conditions are met:

1. Modifications to source code should be reported to: esanchez@mail.sdsu.edu
and a copy of the modified files should be reported once modifications are
completed, unless these modifications are made through the project's GitHub
page: http://www.csrc.sdsu.edu/mtk. Documentation related to said modifications
should be developed and included in any deliverable.

2. Redistributions of source code must be done through direct
downloads from the project's GitHub page: http://www.csrc.sdsu.edu/mtk

3. Redistributions in binary form must reproduce the above copyright notice,
this list of conditions and the following disclaimer in the documentation and/or
other materials provided with the distribution.

4. Usage of the binary form on proprietary applications shall require explicit
prior written permission from the the copyright holders, and due credit should
be given to the copyright holders.

5. Neither the name of the copyright holder nor the names of its contributors
may be used to endorse or promote products derived from this software without
specific prior written permission.

The copyright holders provide no reassurances that the source code provided does
not infringe any patent, copyright, or any other intellectual property rights of
third parties. The copyright holders disclaim any liability to any recipient for
claims brought against recipient by any third party for infringement of that
parties intellectual property rights.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR
ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON
ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <iostream>

#include "mtk.h"

void TestDefaultConstructorFactoryMethodDefault() {

  mtk::Tools::BeginUnitTestNo(1);

  mtk::Interp1D inter;

  bool assertion = inter.ConstructInterp1D();

  if (!assertion) {
    std::cerr << "Mimetic interp could not be built." << std::endl;
  }

  mtk::Tools::EndUnitTestNo(1);
  mtk::Tools::Assert(assertion);
}

void TestReturnAsDenseMatrixWithGrid() {

  mtk::Tools::BeginUnitTestNo(2);

  mtk::Interp1D inter;

  bool assertion = inter.ConstructInterp1D();

  if (!assertion) {
    std::cerr << "Mimetic grad (2nd order) could not be built." << std::endl;
  }

  mtk::UniStgGrid1D grid(0.0, 1.0, 5);

  mtk::DenseMatrix interpm(inter.ReturnAsDenseMatrix(grid));

  assertion =
    assertion && interpm.GetValue(0,0) == 1.0 && interpm.GetValue(5,6) == 1.0;

  mtk::Tools::EndUnitTestNo(2);
  mtk::Tools::Assert(assertion);
}

int main () {

  std::cout << "Testing mtk::Interp1D class." << std::endl;

  TestDefaultConstructorFactoryMethodDefault();
  TestReturnAsDenseMatrixWithGrid();
}
