
// HW-04. Імплементація логера на патернах проектування
//-----------------------------------------------

#pragma once

#include <exception>
#include <filesystem>
#include <iostream>
#include <regex>
#include <string>
#include <vector>

#include "../hpp/FileNumberReader.hpp"
#include "../hpp/FilterFactory.hpp"
#include "../hpp/FilterRegistrar.hpp"
#include "../hpp/NumberProcessor.hpp"
#include "../hpp/Observers.hpp"


using string = std::string;