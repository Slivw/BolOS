#include "hardware/ide/ide.h"
#include "types.h"
#include "io/io.h"

extern int	_asm_pci_check();

void	ide_init()
{
  /* if (_asm_pci_check() == 0) */
  /*   return ; */
  /* outb(PCI_INDEX_FORMAT(0, 0, 0, 8), PCI_INDEX_PORT); */
  /* inb(PCI_DATA_PORT); */
}
