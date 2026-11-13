#ifndef CORIN_ASYNC_VALUE_H
#define CORIN_ASYNC_VALUE_H

#include "future.h"
#include <variant>
#include <memory>

namespace corin {

// Forward declaration of Value type
// This will be defined in interpreter.h
class Value;

// Wrapper for Future<Value> to use in the interpreter
class AsyncValue {
private:
    std::shared_ptr<Future<void*>> future_;
    
public:
    AsyncValue() : future_(std::make_shared<Future<void*>>()) {}
    
    explicit AsyncValue(std::shared_ptr<Future<void*>> f) : future_(std::move(f)) {}
    
    // Check if ready
    bool is_ready() const {
        return future_ && future_->is_ready();
    }
    
    // Get the future
    std::shared_ptr<Future<void*>> get_future() const {
        return future_;
    }
    
    // Wait and get the value (returns void* that will be cast to Value)
    void* get() {
        if (future_) {
            return future_->get();
        }
        return nullptr;
    }
};

} // namespace corin

#endif // CORIN_ASYNC_VALUE_H
