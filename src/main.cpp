#include "Expression.hpp"
#include <fstream>
#include <iomanip>
#include <iterator>
#include <limits>
#include <sstream>
#include <boost/program_options.hpp>

void interpret(std::istream& is);

int main(int argc, char* argv[])
{
	namespace po = boost::program_options;
	po::options_description desc{"Usage: " + std::string{argv[0]} + " [options]"};
	desc.add_options()
		("help", "produce help message")
		("notation", po::value<std::string>(), "set notation (normal, fixed, or scientific)")
		("precision", po::value<int>(), "set precision")
		;

	po::variables_map vm;
	bool help{false};

	try
	{
		std::fstream config{"smi.cfg"};
		po::store(po::parse_command_line(argc, argv, desc), vm);
		po::store(po::parse_config_file(config, desc), vm);
		po::notify(vm);
	}
	catch(...) { help = true; }

	if(vm.count("notation"))
	{
		std::string value{vm["notation"].as<std::string>()};
;
		if(value == "fixed") std::cout << std::fixed;
		else if(value == "scientific") std::cout << std::scientific;
		else if(value != "normal") help = true;
	}

	if(vm.count("precision")) std::cout << std::setprecision(vm["precision"].as<int>());

	if(help || vm.count("help")) std::cout << desc << std::endl;
	else while(true) interpret(std::cin);
}	

void interpret(std::istream& is)
{
	std::cout << ">> ";
	Expression expression;
	is >> expression;

	if(!is)
	{
		is.clear();
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	if(!expression.empty())
	{
		postfix(expression);
		std::cout << evaluate(expression) << std::endl;
	}
}
