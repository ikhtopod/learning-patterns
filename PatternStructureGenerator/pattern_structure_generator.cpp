#include "pattern_structure_generator.h"


void PatternStructureGenerator::
StringToUpperCase(std::string& str) {
	std::transform(str.begin(), str.end(), str.begin(), ::toupper);
}

void PatternStructureGenerator::
StringToLowerCase(std::string& str) {
	std::transform(str.begin(), str.end(), str.begin(), ::tolower);
}


bool PatternStructureGenerator::
IsExistsDirectory(const std::string& patternName) {
	return std::filesystem::exists(patternName) &&
		std::filesystem::is_directory(patternName);
}


void PatternStructureGenerator::
CreateRunFileH(const std::string& patternName) {
	std::ostringstream ostr {};

	std::string big { patternName }; StringToUpperCase(big);
	std::string small { patternName }; StringToLowerCase(small);

	ostr << "#pragma once" << "\n\n";
	ostr << "#ifndef " << big << "_RUN_H" << "\n";
	ostr << "#define " << big << "_RUN_H" << "\n\n";
	ostr << "#include \"" << small << ".h\"" << "\n\n";
	ostr << "namespace " << patternName << " {" << "\n\n";
	ostr << "void Run();" << "\n\n";
	ostr << "}" << "\n\n";
	ostr << "#endif // !" << big << "_RUN_H" << "\n";

	std::ofstream file { patternName + "/run.h", std::ofstream::out };
	file << ostr.str();
	file.close();
}

void PatternStructureGenerator::
CreateRunFileCpp(const std::string& patternName) {
	std::ostringstream ostr {};

	ostr << "#include \"run.h\"" << "\n\n";
	ostr << "namespace " << patternName << " {" << "\n\n";
	ostr << "void Run() {" << "\n\n\n\n" << "}" << "\n\n";
	ostr << "} // namespace " << patternName << "\n";


	std::ofstream file { patternName + "/run.cpp", std::ofstream::out };
	file << ostr.str();
	file.close();
}

void PatternStructureGenerator::
CreateRunFile(const std::string& patternName) {
	CreateRunFileH(patternName);
	CreateRunFileCpp(patternName);
}

void PatternStructureGenerator::
CreatePatterFileH(const std::string& patternName) {
	std::ostringstream ostr {};

	std::string big { patternName }; StringToUpperCase(big);
	std::string small { patternName }; StringToLowerCase(small);

	ostr << "#pragma once" << "\n\n";
	ostr << "#ifndef " << big << "_" << big << "_H" << "\n";
	ostr << "#define " << big << "_" << big << "_H" << "\n\n";
	ostr << "namespace " << patternName << " {" << "\n\n\n\n";
	ostr << "} // namespace " << patternName << "\n\n";
	ostr << "#endif // !" << big << "_" << big << "_H" << "\n";

	std::ofstream file { patternName + "/" + small + ".h", std::ofstream::out };
	file << ostr.str();
	file.close();
}


void PatternStructureGenerator::
CreatePatterFileCpp(const std::string& patternName) {
	std::ostringstream ostr {};

	std::string small { patternName }; StringToLowerCase(small);

	ostr << "#include \"" << small << ".h\"" << "\n\n";
	ostr << "namespace " << patternName << " {" << "\n\n\n\n";
	ostr << "} // namespace " << patternName << "\n";

	std::ofstream file { patternName + "/" + small + ".cpp", std::ofstream::out };
	file << ostr.str();
	file.close();
}



void PatternStructureGenerator::
CreatePatterFile(const std::string& patternName) {
	CreatePatterFileH(patternName);
	CreatePatterFileCpp(patternName);
}


PatternStructureGenerator::
PatternStructureGenerator(const SetOfString& listOfPatterns) :
	m_setOfPatterns(listOfPatterns) {}

void PatternStructureGenerator::
AddPatternName(const std::string& patternName) {
	m_setOfPatterns.insert(patternName);
}

void PatternStructureGenerator::
RemovePatternName(const std::string& patternName) {
	m_setOfPatterns.erase(m_setOfPatterns.find(patternName));
}

bool PatternStructureGenerator::
HasPatternName(const std::string& patternName) const {
	return m_setOfPatterns.count(patternName) != 0;
}

void PatternStructureGenerator::Generate() const {
	for (const auto& patternName : m_setOfPatterns) {
		if (IsExistsDirectory(patternName)) continue;

		std::filesystem::create_directory(patternName);

		CreateRunFile(patternName);
		CreatePatterFile(patternName);

		std::cout << "The structure for the " << patternName << "pattern was generated" << std::endl;
	}
}
