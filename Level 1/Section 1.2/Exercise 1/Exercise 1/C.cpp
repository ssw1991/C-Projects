/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "C.hpp"
#include <iostream>
#include <algorithm>
#include <functional>
#include<array>



/*
inline constexpr C::C(const C& pp) :m_data(pp.m_data) 
{}; // Inline, had to remove print statement to comply with constexpr
*/

C::~C()
    {
     std::cout << "Destructor" << std::endl;
    }  // Destructor

/*
C& C::operator = (const C& source)
    {
        std::cout << "Assignment Overload" << std::endl;
        if (this == &source)
        {
            return *this;
        }
        m_data = source.m_data;
        for (int i = 0; i < m_data.size(); i++)
        {
            m_data[i] = source.m_data[i];
        }
        
        return *this;
    } // Assignment overload
*/

double& C::operator [] (int index)
    {
        std::cout << "Bracket Overload" << std::endl;
        if (index >= m_data.size())
        {
            return m_data[0];
        }
        
        return m_data[index];
    } //Overload to retrieve element i of m_data

int C::Size() const
    {
        std::cout << "Size function" << std::endl;
        return m_data.size();
    }  // Returns size

double C::GetElement(int index) const
    {
        std::cout << "Getter" << std::endl;
        if (index >= m_data.size())
        {
            return m_data[0];
        }
        
        return m_data[index];
    } // Retrieve Element i

void C::SetElement(int index, const double& newVal)
    {
        std::cout << "Setter" << std::endl;
        if (index >= m_data.size())
        {
            return;
        }
        
        m_data[index] = newVal;
    } // Set index at element i

void C::ScalerMult(double factor) noexcept
    {
        std::cout << "ScalerMult called" << std::endl;
        std::transform (m_data.begin(), m_data.end(), m_data.begin(),
                        std::bind (std::multiplies<double>() , factor, std::placeholders::_1));
        
    }; // Multiply by a factor
    
void C::Print() noexcept
    {
        for (int i = 0; i < m_data.size(); i++)
        {
            std::cout<<m_data[i]<< ", ";
        }
        std::cout << std::endl;
    } // Print Array

    




