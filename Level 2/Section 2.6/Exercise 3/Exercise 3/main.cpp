#include <system_error>




int main()
{
	std::error_condition io_error(std::errc::io_error);
	std::error_condition network_unreachable(std::errc::network_unreachable);
	std::error_condition nsfd(std::errc::no_such_file_or_directory);
	std::error_condition notSocket(std::errc::not_a_socket);
	std::error_condition permission_denied(std::errc::permission_denied);

	std::error_condition e1(128, std::generic_category());
	std::error_condition e2 = std::make_error_condition(std::io_errc());

	return 0;
}