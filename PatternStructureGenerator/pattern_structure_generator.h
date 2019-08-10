#pragma once

#ifndef PATTERN_STRUCTURE_GENERATOR_H
#define PATTERN_STRUCTURE_GENERATOR_H

#include <set>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <filesystem>
#include <algorithm>
#include <cctype>

class PatternStructureGenerator {
private:
	using FPath = std::filesystem::path;

public:
	using SetOfString = std::set<std::string>;

private:
	SetOfString m_setOfPatterns {};

private:
	static void StringToUpperCase(std::string& str);
	static void StringToLowerCase(std::string& str);

	static bool IsExistsDirectory(const std::string& patternName);

	static void CreateRunFileH(const std::string& patternName);
	static void CreateRunFileCpp(const std::string& patternName);
	static void CreateRunFile(const std::string& patternName);

	static void CreatePatterFileH(const std::string& patternName);
	static void CreatePatterFileCpp(const std::string& patternName);
	static void CreatePatterFile(const std::string& patternName);

public:
	explicit PatternStructureGenerator(const SetOfString& listOfPatterns);

	void AddPatternName(const std::string& patternName);
	void RemovePatternName(const std::string& patternName);
	bool HasPatternName(const std::string& patternName) const;

	void Generate() const;
};

#endif // !PATTERN_STRUCTURE_GENERATOR_H
