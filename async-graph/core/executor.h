#ifndef ASYNC_GRAPH_ASYNC_GRAPH_CORE_EXECUTOR_H_
#define ASYNC_GRAPH_ASYNC_GRAPH_CORE_EXECUTOR_H_

#include "graph"

class Executor {
   public:
    explicit Executor(Graph graph) : graph_(std::move(graph)){};

   private:
    Graph graph_;
};

#endif  // ASYNC_GRAPH_ASYNC_GRAPH_CORE_EXECUTOR_H_
