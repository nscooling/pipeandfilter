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
#include "IDFilter.h"

class PipelineTests {
protected:
  PipelineTests()
    {}
  Pipe g2f{};
  Pipe f2d{};
  IDFilter id_filter { g2f, f2d };
  GeneratorAdpt ga{ g2f };
  DisplayAdpt   da{ f2d };
  I_Filter*     gf{ &ga };
  I_Filter*     wf{ &id_filter };
  I_Filter*     df{ &da };
  Pipeline      pipeline{};
};


TEST_CASE_FIXTURE(PipelineTests, "initial test") {
  pipeline.add(*gf);
  pipeline.add(*wf);
  pipeline.add(*df);
  pipeline.run();
}

TEST_CASE_FIXTURE(PipelineTests, "change filter type test") {
  IDFilter* filter = dynamic_cast<IDFilter*>(wf);
  if(filter != nullptr) {
    filter->setFilterType(Event::Alarm_t::CAUTION);
  }
  pipeline.add(*gf);
  pipeline.add(*wf);
  pipeline.add(*df);
  pipeline.run();
}


#endif
