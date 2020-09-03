ENTRY(EntryPointSc)
SECTIONS
{
	.text :
	{
		*(.text.EntryPointSc)
		*(.text.EntryPoint)
		*(.text.*)
	}
}
