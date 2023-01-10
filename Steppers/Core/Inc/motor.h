#ifndef __MOTOR_H
#define __MOTOR_H

/* Include des librairies utilisées */

#include <stdio.h>
#include <stdint.h>


/* Déclaration des fonctions */

void motor_set (uint16_t degrees);
void motor_irq_cb(void);


#endif /* __MOTOR_H */
