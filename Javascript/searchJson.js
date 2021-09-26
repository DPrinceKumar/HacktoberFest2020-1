// checks for json fields with string values
// also supports partial search
const jsonFieldWithString = (data, field, stringToMatch) => {
  return data.filter((item) => item[field].includes(stringToMatch));
};
