// ------------------------------------------------------------
// FEABHAS LTD
// Transitioning to C++11 / C++14
// AC++11-401
//
// Pipeline.cpp
//
// ------------------------------------------------------------
#include "Pipeline.h"
#include "IFilter.h"

void Pipeline::add(I_Filter& f)
{
  pipeline.push_back(&f);
}

void Pipeline::run()
{
  for(auto filter : pipeline) {
    filter->execute();
  }
}


#ifdef PIPELINE_WITH_DOCTEST
#include "doctest.h"
#include "Pipe.h"
#include "Generator.h"
#include "Display.h"

class PipelineTests {
protected:
  PipelineTests() = default;
  Pipe p{};
  GeneratorAdpt g{ p };
  DisplayAdpt   d{ p };
  Pipeline pipeline{};
};


TEST_CASE_FIXTURE(PipelineTests, "initial test") {
  pipeline.add(g);
  pipeline.add(d);
  pipeline.run();
}

#endif
