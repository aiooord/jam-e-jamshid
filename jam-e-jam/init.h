#ifndef INIT_H
#define INIT_H

#include <QDebug>
#include <QFile>
#include <QFileDialog>
#include <QObject>

// Define debug mode for conditional debug output
#define debug_module

struct BinaryFormat
{
    QString m_path;
    QString m_name;
    QString m_format;
};

// Define the file format magic numbers for various binaries
const QByteArray ELF_MAGIC    = QByteArray::fromHex("7f454c46"); // ELF files start with 0x7F 'E' 'L' 'F'
const QByteArray PE_MAGIC     = QByteArray::fromHex("4d5a"); // PE files start with 'MZ'
const QByteArray MACH_MAGIC   = QByteArray::fromHex("feedface"); // Mach-O 32-bit
const QByteArray MACH64_MAGIC = QByteArray::fromHex("feedfacf"); // Mach-O 64-bit

class Init : public QObject
{
    Q_OBJECT
public:
    explicit Init(QObject* parent = nullptr);

private:
    BinaryFormat m_binary_format;

public:
    void	 openBinary();
    void	 initBinaryFormat();
    BinaryFormat returnBinaryInformation();
};

#endif // INIT_H
