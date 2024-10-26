#ifndef DISASSEMBLY_ENGINE_H
#define DISASSEMBLY_ENGINE_H

#include <QHeaderView>
#include <QString>
#include <QTableWidget>
#include <capstone/capstone.h>
#include <qt_windows.h>

namespace DisassemblyEngine
{
    namespace Ai000
    {

    }

    namespace Capstone
    {
	void Intel16bit(QByteArray arg_opcode, QTableWidget* arg_table_widget);
	void Intel32bit(QByteArray arg_opcode, QTableWidget* arg_table_widget);
	void Intel64bit(QByteArray arg_opcode, QTableWidget* arg_table_widget);
    }
}

namespace Optimization
{
    namespace Analysis
    {
	// Helper functions for function inlining patterns
	int    SIMDPatterns(cs_insn* arg_insn, size_t arg_count);
	int    PrefetchingPatterns(cs_insn* arg_insn, size_t arg_count);
	int    BranchlessPatterns(cs_insn* arg_insn, size_t arg_count);
	double FunctionInlining(const cs_insn* arg_insns, size_t arg_count);
	double LoopUnrolling(const cs_insn* arg_insns, size_t arg_count);
    }
}

#endif // DISASSEMBLY_ENGINE_H
