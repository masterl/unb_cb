# ISBN

The purpose of this project was to familiarize the students with C by implementing a program to validate ISBN numbers.

## Directions

- Receive a 10 or 13 digit ISBN as input
- Check if it's valid
- Output:
  - Confirmation of the ISBN validity (or if it isn't)
  - Book Country
    - Brazil = 85
    - United Kingdom = 1
    - France = 2
    - Russia = 5
    - Argentina = 950
    - Others

### ISBN structure

- Prefix (3 digits)
- Registration group (country)
- Registration element
- Publication element
- Check digit (1 digit)

#### Verification for 10 digits

verification_digit=(1 * isbn[0] +
2 * isbn[1] +
3 * isbn[2] +
4 * isbn[3] +
5 * isbn[4] +
6 * isbn[5] +
7 * isbn[6] +
8 * isbn[7] +
9 * isbn[8]) % 11

If remainder is 10, verification_digit is X

Then check
verification_digit == isbn[9]

#### Verification for 13 digits

verification_digit=(1 * isbn[0] +
3 * isbn[1] +
1 * isbn[2] +
3 * isbn[3] +
1 * isbn[4] +
3 * isbn[5] +
1 * isbn[6] +
3 * isbn[7] +
1 * isbn[8] +
3 * isbn[9] +
1 * isbn[10] +
3 * isbn[11]) % 10

verification_digit = 10 - verification_digit


Then check
if verification_digit < 10
  verification_digit == isbn[12]
else
  isbn[12] == 0
