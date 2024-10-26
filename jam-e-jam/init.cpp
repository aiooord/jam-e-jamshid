#include "init.h"

Init::Init(QObject* parent)
    : QObject { parent }
{
}

void Init::openBinary()
{
    // Platform-specific file filters
    QString filter_for_pe    = "PE Files (*.exe *.dll *.lib);;";
    QString filter_for_elf   = "ELF Files (*.so *.out *.a);;";
    QString filter_for_macho = "Mach-O Files (*.dylib *.bundle);;";
    QString filter_for_all   = "All Files (*.*)";

    // Combine filters
    QString filter_for_final = filter_for_pe + filter_for_elf + filter_for_macho + filter_for_all;

    // Open file dialog with the combined filter
    m_binary_format.m_path   = QFileDialog::getOpenFileName(nullptr, "Open Binary File", "", filter_for_final);

    // Check if a file was selected
    if (m_binary_format.m_path.isEmpty())
    {
#ifdef debug_module
	qDebug() << "No file selected.";
#endif
	return;
    }

#ifdef debug_module
    qDebug() << "File selected:" << m_binary_format.m_path;
#endif

    // Extract the file name using QFileInfo
    QFileInfo file_info(m_binary_format.m_path);
    // Save only the file name
    m_binary_format.m_name = file_info.fileName();

#ifdef debug_module
    qDebug() << "File name saved:" << m_binary_format.m_name;
#endif
}

void Init::initBinaryFormat()
{
    QFile file(m_binary_format.m_path);
    if (!file.open(QIODevice::ReadOnly))
    {
#ifdef debug_module
	qDebug() << "Could not open file:" << m_binary_format.m_path;
#endif
	return;
    }

    // Read the first few bytes for magic number detection
    QByteArray binary_header = file.read(4);
    file.close();

    // Check for known magic numbers
    if (binary_header.startsWith(ELF_MAGIC))
    {
	// Linux Executable and Linking Format
	m_binary_format.m_format = "ELF";
    }
    else if (binary_header.startsWith(PE_MAGIC))
    {
	// Windows Portable Executable
	m_binary_format.m_format = "PE";
    }
    else if (binary_header.startsWith(MACH_MAGIC) || binary_header.startsWith(MACH64_MAGIC))
    {
	// macOS executable format
	m_binary_format.m_format = "Mach-O";
    }
    else
    {
	// Fallback: use file extension if format is unknown
	QFileInfo fileInfo(m_binary_format.m_path);
	m_binary_format.m_format = fileInfo.suffix();
    }
}

BinaryFormat Init::returnBinaryInformation()
{
    initBinaryFormat();
    return m_binary_format;
}
