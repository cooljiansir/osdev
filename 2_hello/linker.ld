ENTRY(start)
. = 0x4000000;
	SECTIONS 
{
	.text : 
	{
	*(.text)
	}
	. = ALIGN(0x1000);
	.rodata :
	{
	*(.rodata)
	}
	. = ALIGN(0x1000);
	.data : 
	{
	*(.data)
	}
	. = ALIGN(0x1000);
	.bss :
	{
	*(.bss)
	*(COMMON)
	}
}
