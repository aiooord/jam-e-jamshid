#include "disassembly_engine.h"
#include <iostream>

// Include Ai000 Capstone namespace
namespace DisassemblyEngine
{
    namespace Capstone
    {
	void Intel16bit(QByteArray arg_opcode, QTableWidget* arg_table_widget)
	{
	    // Initialize Capstone
	    csh	   capstone_engine_handle;
	    cs_err capstone_error = cs_open(CS_ARCH_X86, CS_MODE_16, &capstone_engine_handle);
	    if (capstone_error != CS_ERR_OK)
	    {
		throw std::runtime_error("Capstone initialization has been failed..");
	    }

	    // Disassemble the code
	    size_t   count;
	    cs_insn* insn;

	    // Assuming a base address of 0x1000
	    count = cs_disasm(capstone_engine_handle, reinterpret_cast<const uint8_t*>(arg_opcode.constData()), arg_opcode.size(), 0x1000, 0, &insn);

	    if (count > 0)
	    {
		// Clear the tableWidget
		arg_table_widget->clear();
		arg_table_widget->setRowCount(static_cast<int>(count));
		arg_table_widget->setColumnCount(5);
		QStringList headers = { "Address", "Byte Code", "Mnemonic", "Operands", "Comment" };
		arg_table_widget->setHorizontalHeaderLabels(headers);

		// Set the tableWidget styles and set header text color to red
		arg_table_widget->horizontalHeader()->setStyleSheet("QHeaderView::section { background-color: black; color: yellow; font-weight: bold; }");
		arg_table_widget->verticalHeader()->setStyleSheet("QHeaderView::section { background-color: red; color: white; font-weight: bold; }");
		arg_table_widget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

		for (int i = 0; i < arg_table_widget->rowCount(); i++)
		{
		    for (int j = 0; j < arg_table_widget->columnCount(); j++)
		    {
			QTableWidgetItem* item = new QTableWidgetItem();
			if (j == 0)
			{
			    item->setText(QString("0x%1").arg(insn[i].address, 0, 16));
			    QBrush brush;
			    brush.setColor(Qt::blue);
			    item->setForeground(brush);
			    item->setTextAlignment(Qt::AlignLeft);
			}
			else if (j == 1)
			{
			    QString byte_code;
			    for (size_t k = 0; k < insn[i].size; k++)
			    {
				byte_code += QString("%1 ").arg(static_cast<unsigned>(insn[i].bytes[k]), 2, 16, QChar('0')).toUpper();
			    }
			    item->setText(byte_code.trimmed());
			}
			else if (j == 2)
			{
			    item->setText(QString::fromUtf8(insn[i].mnemonic));
			    item->setTextAlignment(Qt::AlignLeft);
			}
			else if (j == 3)
			{
			    item->setText(QString::fromUtf8(insn[i].op_str));
			    item->setTextAlignment(Qt::AlignLeft);
			}
			else if (j == 4)
			{
			    item->setText(" ");
			    item->setTextAlignment(Qt::AlignLeft);
			}
			else if (j == 5)
			{
			    item->setText(" ");
			    item->setTextAlignment(Qt::AlignLeft);
			}
			arg_table_widget->setItem(i, j, item);
			if (j != 0)
			{
			    item->setBackground(QColor(240, 240, 240));
			    item->setData(Qt::UserRole, 10);
			}
		    }
		}
		cs_free(insn, count);
	    }
	    else
	    {
		throw std::runtime_error("Disassembly process by capstone failed.");
	    }

	    cs_close(&capstone_engine_handle);
	}

	void Intel32bit(QByteArray arg_opcode, QTableWidget* arg_table_widget)
	{
	    // Initialize Capstone for 32-bit Intel architecture
	    csh	   capstone_engine_handle;
	    cs_err capstone_error = cs_open(CS_ARCH_X86, CS_MODE_32, &capstone_engine_handle);
	    if (capstone_error != CS_ERR_OK)
	    {
		throw std::runtime_error("Capstone initialization has failed.");
	    }

	    // Disassemble the code
	    size_t   count;
	    cs_insn* insn;

	    // Assuming a base address of 0x1000
	    count = cs_disasm(capstone_engine_handle, reinterpret_cast<const uint8_t*>(arg_opcode.constData()), arg_opcode.size(), 0x1000, 0, &insn);

	    if (count > 0)
	    {
		// Clear the tableWidget
		arg_table_widget->clear();
		arg_table_widget->setRowCount(static_cast<int>(count));
		arg_table_widget->setColumnCount(5);
		QStringList headers = { "Address", "Byte Code", "Mnemonic", "Operands", "Comment" };
		arg_table_widget->setHorizontalHeaderLabels(headers);

		// Set the tableWidget styles
		arg_table_widget->horizontalHeader()->setStyleSheet("QHeaderView::section { background-color: black; color: yellow; font-weight: bold; }");
		arg_table_widget->verticalHeader()->setStyleSheet("QHeaderView::section { background-color: red; color: white; font-weight: bold; }");
		arg_table_widget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

		for (int i = 0; i < arg_table_widget->rowCount(); i++)
		{
		    for (int j = 0; j < arg_table_widget->columnCount(); j++)
		    {
			QTableWidgetItem* item = new QTableWidgetItem();
			if (j == 0) // Address column
			{
			    // Format the address as 4-byte (8 hex digits)
			    item->setText(QString("0x%1").arg(insn[i].address, 8, 16, QChar('0')).toUpper());
			    QBrush brush;
			    brush.setColor(Qt::blue);
			    item->setForeground(brush);
			    item->setTextAlignment(Qt::AlignLeft);
			}
			else if (j == 1) // Byte Code column
			{
			    QString byte_code;
			    for (size_t k = 0; k < insn[i].size; k++)
			    {
				byte_code += QString("%1 ").arg(static_cast<unsigned>(insn[i].bytes[k]), 2, 16, QChar('0')).toUpper();
			    }
			    item->setText(byte_code.trimmed());
			}
			else if (j == 2) // Mnemonic column
			{
			    item->setText(QString::fromUtf8(insn[i].mnemonic));
			    item->setTextAlignment(Qt::AlignLeft);
			}
			else if (j == 3) // Operands column
			{
			    item->setText(QString::fromUtf8(insn[i].op_str));
			    item->setTextAlignment(Qt::AlignLeft);
			}
			else if (j == 4) // Comment column
			{
			    item->setText(" "); // Placeholder for the comment
			    item->setTextAlignment(Qt::AlignLeft);
			}
			arg_table_widget->setItem(i, j, item);
			if (j != 0)
			{
			    item->setBackground(QColor(240, 240, 240));
			    item->setData(Qt::UserRole, 10);
			}
		    }
		}
		cs_free(insn, count);
	    }
	    else
	    {
		throw std::runtime_error("Disassembly process by Capstone failed.");
	    }

	    cs_close(&capstone_engine_handle);
	}

	void Intel64bit(QByteArray arg_opcode, QTableWidget* arg_table_widget)
	{
	    // Initialize Capstone for x64 Intel architecture
	    csh	   capstone_engine_handle;
	    cs_err capstone_error = cs_open(CS_ARCH_X86, CS_MODE_64, &capstone_engine_handle);
	    if (capstone_error != CS_ERR_OK)
	    {
		throw std::runtime_error("Capstone initialization has failed.");
	    }

	    if (arg_opcode.isEmpty())
	    {
		throw std::runtime_error("Opcode data is empty.");
	    }

	    // Disassemble the code
	    size_t   count;
	    cs_insn* insn;

	    // Assuming a base address of 0x1000
	    count = cs_disasm(capstone_engine_handle, reinterpret_cast<const uint8_t*>(arg_opcode.constData()), arg_opcode.size(), 0x1000, 0, &insn);

	    if (count > 0)
	    {
		// Clear the tableWidget
		arg_table_widget->clear();
		arg_table_widget->setRowCount(static_cast<int>(count));
		arg_table_widget->setColumnCount(5);
		QStringList headers = { "Address", "Byte Code", "Mnemonic", "Operands", "Comment" };
		arg_table_widget->setHorizontalHeaderLabels(headers);

		// Set the tableWidget styles and set header text color to red
		arg_table_widget->horizontalHeader()->setStyleSheet("QHeaderView::section { background-color: black; color: yellow; font-weight: bold; }");
		arg_table_widget->verticalHeader()->setStyleSheet("QHeaderView::section { background-color: red; color: white; font-weight: bold; }");
		arg_table_widget->horizontalHeader()->setDefaultAlignment(Qt::AlignLeft);

		for (int i = 0; i < arg_table_widget->rowCount(); i++)
		{
		    for (int j = 0; j < arg_table_widget->columnCount(); j++)
		    {
			QTableWidgetItem* item = new QTableWidgetItem();
			if (j == 0)
			{
			    // Format the address safely
			    item->setText(QString("0x%1").arg(static_cast<quint64>(insn[i].address), 16, 16, QChar('0')));
			    QBrush brush;
			    brush.setColor(Qt::blue);
			    item->setForeground(brush);
			    item->setTextAlignment(Qt::AlignLeft);
			}
			else if (j == 1)
			{
			    // Format the byte code safely
			    QString byte_code;
			    for (size_t k = 0; k < insn[i].size; k++)
			    {
				byte_code += QString("%1 ").arg(static_cast<unsigned int>(insn[i].bytes[k]), 2, 16, QChar('0')).toUpper();
			    }
			    item->setText(byte_code.trimmed());
			}
			else if (j == 2)
			{
			    item->setText(QString::fromUtf8(insn[i].mnemonic));
			    item->setTextAlignment(Qt::AlignLeft);
			}
			else if (j == 3)
			{
			    item->setText(QString::fromUtf8(insn[i].op_str));
			    item->setTextAlignment(Qt::AlignLeft);
			}
			else if (j == 4)
			{
			    item->setText(" "); // Placeholder for "Lift" column
			    item->setTextAlignment(Qt::AlignLeft);
			}
			else if (j == 5)
			{
			    item->setText(" "); // Placeholder for "Comment" column
			    item->setTextAlignment(Qt::AlignLeft);
			}
			arg_table_widget->setItem(i, j, item);
			if (j != 0)
			{
			    item->setBackground(QColor(240, 240, 240));
			    item->setData(Qt::UserRole, 10);
			}
		    }
		}
		cs_free(insn, count);
	    }
	    else
	    {
		throw std::runtime_error("Disassembly process by Capstone failed.");
	    }

	    cs_close(&capstone_engine_handle);
	}
    };
};

int Optimization::Analysis::SIMDPatterns(cs_insn* arg_insn, size_t arg_count)
{
    int simd_score = 0;
    for (size_t i = 0; i < arg_count; i++)
    {
	// Look for SIMD instructions (MOVDQA, ADDPS, etc.)
	// Works for both EXEs and DLLs as they share the same instruction sets
	if (strstr(arg_insn[i].mnemonic, "movdqa") || strstr(arg_insn[i].mnemonic, "addps") || strstr(arg_insn[i].mnemonic, "mulps") || strstr(arg_insn[i].mnemonic, "subps") || strstr(arg_insn[i].mnemonic, "divps"))
	{
	    simd_score += 1; // Increment score for each SIMD instruction
	}
    }
    return simd_score;
}

int Optimization::Analysis::PrefetchingPatterns(cs_insn* arg_insn, size_t arg_count)
{
    int prefetch_score = 0;
    for (size_t i = 0; i < arg_count; i++)
    {
	// Look for prefetch instructions like PREFETCH, PREFETCHW, PREFETCHNTA
	if (strstr(arg_insn[i].mnemonic, "prefetch") || strstr(arg_insn[i].mnemonic, "prefetchw") || strstr(arg_insn[i].mnemonic, "prefetchnta"))
	{
	    prefetch_score += 1; // Increment score for each prefetch instruction
	}
    }
    return prefetch_score;
}

int Optimization::Analysis::BranchlessPatterns(cs_insn* arg_insn, size_t arg_count)
{
    int branchless_score = 0;
    for (size_t i = 0; i < arg_count; i++)
    {
	// Look for conditional move instructions and set instructions (branchless patterns)
	if (strstr(arg_insn[i].mnemonic, "cmov") || strstr(arg_insn[i].mnemonic, "set") || strstr(arg_insn[i].mnemonic, "setz") || strstr(arg_insn[i].mnemonic, "setnz"))
	{
	    branchless_score += 1; // Increment score for each branchless pattern
	}
    }
    return branchless_score;
}

double Optimization::Analysis::FunctionInlining(const cs_insn* arg_insns, size_t arg_count)
{
    size_t call_count = 0;

    // Iterate over instructions to detect "call" instructions
    for (size_t i = 0; i < arg_count; ++i)
    {
	if (strcmp(arg_insns[i].mnemonic, "call") == 0)
	{
	    call_count++;
	}
    }

    // If there are very few function calls, inlining likely occurred
    if (call_count == 0)
    {
	return 1.0; // Highly inlined
    }
    else if (call_count < arg_count * 0.01) // If less than 1% of instructions are calls
    {
	return 0.7; // Moderate inlining
    }
    else
    {
	return 0.2; // Low inlining
    }
}

double Optimization::Analysis::LoopUnrolling(const cs_insn* arg_insns, size_t arg_count)
{
    size_t repeated_patterns = 0;
    size_t sequence_length   = 5; // Arbitrarily chosen sequence length to detect unrolling

    // Loop through and compare sequences of instructions
    for (size_t i = 0; i < arg_count - sequence_length; ++i)
    {
	bool is_repeated = true;

	// Check for repeated instruction sequences of a certain length
	for (size_t j = 0; j < sequence_length; ++j)
	{
	    if (strcmp(arg_insns[i + j].mnemonic, arg_insns[i + j + sequence_length].mnemonic) != 0)
	    {
		is_repeated = false;
		break;
	    }
	}

	// If a repeated pattern is found, count it as unrolling
	if (is_repeated)
	{
	    repeated_patterns++;
	    i += sequence_length; // Skip ahead to avoid double-counting overlapping patterns
	}
    }

    // If we found a significant number of repeated patterns, we assume loop unrolling
    if (repeated_patterns > arg_count * 0.01)
    {
	return 1.0; // High loop unrolling
    }
    else if (repeated_patterns > arg_count * 0.005)
    {
	return 0.7; // Moderate loop unrolling
    }
    else
    {
	return 0.2; // Low or no loop unrolling
    }
}
