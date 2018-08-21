/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   C.h
 * Author: wilsons
 *
 * Created on May 10, 2018, 6:29 PM
 */



#ifndef C_H
#define C_H
#include<array>
#include<iostream>

class C
{
private:
    std::array<double, 10> m_data; // std::array so it can be known at compile time
  
    
public:
    // Constructors
	C() = default;
	constexpr C(double i) : m_data(std::array<double, 10>{i, i, i, i, i, i, i, i, i, i})
	{}; // Inlined.  For somereason, when constructing the body in the .cpp file, using the inline keyword this did not work

	explicit constexpr C(const C& pp) = delete;
    ~C();
    
    // Member operator overloading
    C& operator = (const C& source) = delete;
    double& operator [] (int index);
   
    
    // Accessing functions
    int Size() const;
    double GetElement(int index) const;
    void Print() noexcept;
    
    // Modifiers
    void SetElement(int index, const double& new_val);
    void ScalerMult(double factor) noexcept;
    
};


#endif

