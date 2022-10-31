#ifndef ASYNC_GRAPH_ASYNC_GRAPH_CORE_GRAPHFRAME_H_
#define ASYNC_GRAPH_ASYNC_GRAPH_CORE_GRAPHFRAME_H_

#include <vector>
#include <future>
#include <any>

class KernelFrame
{
   public:
    using ValueType = std::any;
    template <class T>
    void AddInput(T&& val){
        inputs_.emplace_back(std::forward<T>(val));
    }

    template <class T>
    T GetInput(int idx){
        return std::any_cast<T>(inputs_[idx]);
    }

    template <class T>
    void SetOutput(T&& val){
        results_.emplace_back(std::forward<T>(val));
    }

    template <class T>
    T GetOutput(int idx){
        return std::any_cast<T>(results_[idx]);
    }

   private:
    std::vector<ValueType> inputs_;
    std::vector<ValueType> results_;
};

#endif  // ASYNC_GRAPH_ASYNC_GRAPH_CORE_GRAPHFRAME_H_
