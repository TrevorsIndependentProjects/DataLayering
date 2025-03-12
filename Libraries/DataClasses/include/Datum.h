// Trevor Holland
// Created: November 23, 2023

#ifndef DATACLASSES_DATUM_H
#define DATACLASSES_DATUM_H

#include <string>
#include <ostream>
#include "DataType.h"

namespace DataClasses {
    // ==========================================================
    // Datum template interface
    // ==========================================================
    template <typename T>
    class Datum {
    public:
        Datum();
        Datum(const std::string& name);
        Datum(const std::string& name, const T& value);
        Datum(const Datum& other);
        Datum(Datum&& other) = default;
        Datum& operator=(const Datum& other);
        
        virtual ~Datum() = default;

        bool isEmpty() const; 
        std::string getName() const;
        std::string valueToString() const;
        DataType getType() const;
        void setName(const std::string& name);

        bool operator==(const Datum& rhs) const;
        bool operator!=(const Datum& rhs) const;

        void setValue(const T& value);

        int valueToInt() const;
        double valueToDouble() const;
        size_t valueToCount() const;
        bool valueToBool() const;

        friend std::ostream& operator<<(std::ostream& os, const Datum<T>& d);
    private:
        std::string m_name;
        std::string m_value;
        DataType m_type;
    };

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Datum<T>& d);

    // ==========================================================
    // Templated implementations
    // ==========================================================
    template <typename T>
    Datum<T>::Datum() : m_type(DataType::kUnknown) {}

    template <typename T>
    Datum<T>::Datum(const std::string& name) 
        : Datum() { m_name = name; }
    
    template <typename T>
    Datum<T>::Datum(const std::string& name, const T& value) 
        : Datum(name) { setValue(value); }

    template <typename T>
    Datum<T>::Datum(const Datum& other) 
        { *this = other; }

    template <typename T>
    Datum<T>& Datum<T>::operator=(const Datum<T>& other) {
        m_name = other.m_name;
        m_value = other.m_value;
        m_type = other.m_type;
        return *this;
    }

    template <typename T>
    bool Datum<T>::isEmpty() const { return m_value.empty(); }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Datum<T>& d) {
        strm << d.getName() << "=" << d.valueToString();
        return os;
    }

    template <typename T>
    std::string Datum<T>::getName() const { return m_name; }

    template <typename T>
    std::string Datum<T>::valueToString() const { return m_value; }

    template <typename T>
    DataType Datum<T>::getType() const { return m_type; }

    template <typename T>
    void Datum<T>::setName(const std::string& name) { m_name = name; }

    template <typename T>
    bool Datum<T>::operator==(const Datum<T>& rhs) const {
        return m_name == rhs.m_name
            && m_type == rhs.m_type
            && m_value == rhs.m_value;
    }

    template <typename T>
    bool Datum<T>::operator!=(const Datum<T>& rhs) const { return !(*this == rhs); }

    template <typename T>
    void Datum<T>::setValue(const T& value) {}

    // ==========================================================
    // Typed constructors
    template<>
    inline Datum<int>::Datum() : m_type(DataType::kInteger) {}

    template<>
    inline Datum<std::string>::Datum() : m_type(DataType::kString) {}

    template<>
    inline Datum<size_t>::Datum() : m_type(DataType::kCount) {}

    template<>
    inline Datum<double>::Datum() : m_type(DataType::kDecimal) {}

    template<>
    inline Datum<bool>::Datum() : m_type(DataType::kFlag) {}

    // ==========================================================
    // Typed setters
    template <>
    inline void Datum<int>::setValue(const int& value) {
        m_value = std::to_string(value);
    }

    template <>
    inline void Datum<std::string>::setValue(const std::string& value) {
        m_value = value;
    }

    template <>
    inline void Datum<double>::setValue(const double& value) {
        m_value = std::to_string(value);
    }

    template <>
    inline void Datum<size_t>::setValue(const size_t& value) {
        m_value = std::to_string(value);
    }

    template <>
    inline void Datum<bool>::setValue(const bool& value) {
        if (value)
            m_value = "true";
        else
            m_value = "false";
    }

    // ==========================================================
    // Typed getters (only available to specific types)
    template <>
    inline int Datum<int>::valueToInt() const {
        return std::stoi(m_value);
    }

    template <>
    inline bool Datum<bool>::valueToBool() const {
        if (m_value == "true")
            return true;

        return false;
    }

    template<>
    inline size_t Datum<size_t>::valueToCount() const {
        return std::stoull(m_value);
    }

    template<>
    inline double Datum<double>::valueToDouble() const {
        return std::stod(m_value);
    }

    // ==========================================================
    // Defining types

    using StringDatum = Datum<std::string>;
    using IntegerDatum = Datum<int>;
    using CountDatum = Datum<size_t>;
    using DecimalDatum = Datum<double>;
    using FlagDatum = Datum<bool>;

}
#endif // !DATACLASSES_DATUM_H
