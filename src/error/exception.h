#ifndef CORIN_EXCEPTION_H
#define CORIN_EXCEPTION_H

#include <exception>
#include <string>
#include <vector>

namespace corin {

// Stack frame information for better error reporting
struct StackFrame {
    std::string function_name;
    std::string file_name;
    int line_number;
    int column_number;
    
    StackFrame(const std::string& func, const std::string& file, int line, int col = 0)
        : function_name(func), file_name(file), line_number(line), column_number(col) {}
        
    std::string toString() const {
        return "  at " + function_name + " (" + file_name + ":" + std::to_string(line_number) + 
               (column_number > 0 ? ":" + std::to_string(column_number) : "") + ")";
    }
};

// Base exception class for all Corin exceptions
class CorinException : public std::exception {
protected:
    std::string message;
    std::string type_name;
    std::vector<StackFrame> stack_trace;
    int line_number;
    int column_number;
    std::string file_name;
    std::string suggestion;
    
public:
    CorinException(const std::string& msg, const std::string& type)
        : message(msg), type_name(type), line_number(-1), column_number(-1) {}
    
    CorinException(const std::string& msg, const std::string& type, 
                     const std::string& file, int line, int col = -1)
        : message(msg), type_name(type), line_number(line), column_number(col), file_name(file) {}
    
    const char* what() const noexcept override {
        return message.c_str();
    }
    
    std::string getTypeName() const { return type_name; }
    std::string getMessage() const { return message; }
    std::string getFileName() const { return file_name; }
    int getLineNumber() const { return line_number; }
    int getColumnNumber() const { return column_number; }
    std::string getSuggestion() const { return suggestion; }
    
    void setLocation(const std::string& file, int line, int col = -1) {
        file_name = file;
        line_number = line;
        column_number = col;
    }
    
    void setSuggestion(const std::string& hint) {
        suggestion = hint;
    }
    
    void addStackFrame(const StackFrame& frame) {
        stack_trace.push_back(frame);
    }
    
    std::string getFullErrorMessage() const {
        std::string full_msg = type_name + ": " + message;
        
        if (!file_name.empty() && line_number > 0) {
            full_msg += "\n  at " + file_name + ":" + std::to_string(line_number);
            if (column_number > 0) {
                full_msg += ":" + std::to_string(column_number);
            }
        }
        
        if (!stack_trace.empty()) {
            full_msg += "\n\nStack trace:";
            for (const auto& frame : stack_trace) {
                full_msg += "\n" + frame.toString();
            }
        }
        
        if (!suggestion.empty()) {
            full_msg += "\n\nSuggestion: " + suggestion;
        }
        
        return full_msg;
    }
    
    const std::vector<StackFrame>& getStackTrace() const { return stack_trace; }
};

// Built-in exception types

class RuntimeError : public CorinException {
public:
    explicit RuntimeError(const std::string& msg) 
        : CorinException(msg, "RuntimeError") {}
        
    RuntimeError(const std::string& msg, const std::string& file, int line, int col = -1)
        : CorinException(msg, "RuntimeError", file, line, col) {}
};

class DivisionByZeroError : public CorinException {
public:
    explicit DivisionByZeroError(const std::string& msg) 
        : CorinException(msg, "DivisionByZeroError") {}
        
    DivisionByZeroError(const std::string& msg, const std::string& file, int line, int col = -1)
        : CorinException(msg, "DivisionByZeroError", file, line, col) {}
};

class FileNotFoundError : public CorinException {
public:
    explicit FileNotFoundError(const std::string& msg) 
        : CorinException(msg, "FileNotFoundError") {}
        
    FileNotFoundError(const std::string& msg, const std::string& file, int line, int col = -1)
        : CorinException(msg, "FileNotFoundError", file, line, col) {}
};

class IndexError : public CorinException {
public:
    explicit IndexError(const std::string& msg) 
        : CorinException(msg, "IndexError") {}
        
    IndexError(const std::string& msg, const std::string& file, int line, int col = -1)
        : CorinException(msg, "IndexError", file, line, col) {}
};

class TypeError : public CorinException {
public:
    explicit TypeError(const std::string& msg) 
        : CorinException(msg, "TypeError") {}
        
    TypeError(const std::string& msg, const std::string& file, int line, int col = -1)
        : CorinException(msg, "TypeError", file, line, col) {}
};

class ValueError : public CorinException {
public:
    explicit ValueError(const std::string& msg) 
        : CorinException(msg, "ValueError") {}
        
    ValueError(const std::string& msg, const std::string& file, int line, int col = -1)
        : CorinException(msg, "ValueError", file, line, col) {}
};

class PermissionError : public CorinException {
public:
    explicit PermissionError(const std::string& msg)
        : CorinException(msg, "PermissionError") {}
        
    PermissionError(const std::string& msg, const std::string& file, int line, int col = -1)
        : CorinException(msg, "PermissionError", file, line, col) {}
};

// JSON-specific errors
class JSONParseError : public CorinException {
public:
    explicit JSONParseError(const std::string& msg)
        : CorinException(msg, "JSONParseError") {}
        
    JSONParseError(const std::string& msg, const std::string& file, int line, int col = -1)
        : CorinException(msg, "JSONParseError", file, line, col) {}
};

} // namespace corin

#endif // CORIN_EXCEPTION_H
