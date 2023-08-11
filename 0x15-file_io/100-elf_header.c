#include <elf.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void check_elf(unsigned char *e_ident);
void print_headers(unsigned char *e_ident);
void print_type(unsigned int e_type, unsigned char *e_ident);
void print_entry(unsigned long int e_entry, unsigned char *e_ident);
void close_elf(int elf);
/**
 * check_elf - This checks if a given file is an ELF file.
 * @e_ident: This a pointer to an array containing the ELF magic numbers.
 *
 * Description: If the given file is not an ELF file - exit the at code 98.
 */

void check_elf(unsigned char *e_ident)
	{
	int index;
	char *err_msg = "Error: Not an ELF file\n";

	for (index = 0; index < 4; index++)
	if (e_ident[index] != 127 &&
	e_ident[index] != 'E' &&
	e_ident[index] != 'L' &&
	e_ident[index] != 'F')
	dprintf(STDERR_FILENO, "%s", err_msg), exit(98);
	}
/**
 * print_magic - This prints the magic numbers of the ELF header.
 * @e_ident: This a pointer to an array that contains the ELF magic numbers.
 *
 * Description: The given magic numbers are separated by spaces.
 */

void print_headers(unsigned char *e_ident)
	{
	int i;

	printf(" ELF Header:\n Magic: ");
	for (i = 0; i < EI_NIDENT; i++)
	printf("%02x%s", e_ident[i], i == EI_NIDENT - 1 ? "\n" : " ");
	printf(" Class: %s\n", e_ident[EI_CLASS] == ELFCLASSNONE ? "none" :
	e_ident[EI_CLASS] == ELFCLASS32 ? "ELF32" :
	e_ident[EI_CLASS] == ELFCLASS64 ? "ELF64" : "<unknown>");
	printf(" Data: %s\n", e_ident[EI_DATA] == ELFDATANONE ? "none" :
	e_ident[EI_DATA] == ELFDATA2LSB ? "2's complement, little endian" :
	e_ident[EI_DATA] == ELFDATA2MSB ?
	"2's complement, big endian" : "<unknown>");
	printf(" Version: %d%s\n", e_ident[EI_VERSION],
	e_ident[EI_VERSION] == EV_CURRENT ? " (current)" : "");
	printf(" OS/ABI: %s\n", e_ident[EI_OSABI]
	== ELFOSABI_NONE ? "UNIX - System V" :
	e_ident[EI_OSABI] == ELFOSABI_HPUX ? "UNIX - HP-UX" :
	e_ident[EI_OSABI] == ELFOSABI_NETBSD ? "UNIX - NetBSD" :
	e_ident[EI_OSABI] == ELFOSABI_LINUX ? "UNIX - Linux" :
	e_ident[EI_OSABI] == ELFOSABI_SOLARIS ? "UNIX - Solaris" :
	e_ident[EI_OSABI] == ELFOSABI_IRIX ? "UNIX - IRIX" :
	e_ident[EI_OSABI] == ELFOSABI_FREEBSD ? "UNIX - FreeBSD" :
	e_ident[EI_OSABI] == ELFOSABI_TRU64 ? "UNIX - TRU64" :
	e_ident[EI_OSABI] == ELFOSABI_ARM ? "ARM" :
	e_ident[EI_OSABI] == ELFOSABI_STANDALONE ? "Standalone App" : "<unknown>");
	printf(" ABI Version: %d\n", e_ident[EI_ABIVERSION]);

	}
/**
 * print_class - This prints the class of an ELF header.
 * @e_ident: This a pointer to an array containing the ELF class.
 */

void print_type(unsigned int e_type, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	e_type >>= 8;
	printf(" Type: %s\n", e_type == ET_NONE ? "NONE (None)" :
	e_type == ET_REL ? "REL (Relocatable file)" :
	e_type == ET_EXEC ? "EXEC (Executable file)" :
	e_type == ET_DYN ? "DYN (Shared object file)" :
	e_type == ET_CORE ? "CORE (Core file)" : "<unknown>");
}

void print_entry(unsigned long int e_entry, unsigned char *e_ident)
{
	if (e_ident[EI_DATA] == ELFDATA2MSB)
	{
	e_entry = ((e_entry << 8) & 0xFF00FF00) |
	((e_entry >> 8) & 0xFF00FF);
	e_entry = (e_entry << 16) | (e_entry >> 16);
	}
	printf(" Entry point address: %#lx\n",
	e_ident[EI_CLASS] == ELFCLASS32 ? (unsigned int)e_entry : e_entry);
}

void close_elf(int elf)
{
	if (close(elf) == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't close fd %d\n", elf);
	exit(98);
	}
}

int main(int __attribute__((__unused__)) argc, char *argv[])
	{
	Elf64_Ehdr *header;
	int o, r;

	o = open(argv[1], O_RDONLY);
	if (o == -1)
	{
	dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
	exit(98);
	}
	header = malloc(sizeof(Elf64_Ehdr));
	if (header == NULL)
	{
	close_elf(o);
	dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
	exit(98);
	}
	r = read(o, header, sizeof(Elf64_Ehdr));
	if (r == -1)
	{
	free(header);
	close_elf(o);
	dprintf(STDERR_FILENO, "Error: `%s`: No such file\n", argv[1]);
	exit(98);
	}

	check_elf(header->e_ident);
	print_headers(header->e_ident);
	print_type(header->e_type, header->e_ident);
	print_entry(header->e_entry, header->e_ident);

	free(header);
	close_elf(o);
	return (0);
}
