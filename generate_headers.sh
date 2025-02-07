#!/bin/sh
SCRIPT_DIR=$(dirname $(readlink -f "$0"))
PUBLIC_DATA_TYPES_DIR=$SCRIPT_DIR/public_regulated_data_types
RR_DATA_TYPES_DIR=$SCRIPT_DIR/rr_data_types
OUTPUT_DIR=$SCRIPT_DIR/rr_data_types_header
CYPHAL_SRC_DIR=$SCRIPT_DIR/src
HEADER_DIR=$CYPHAL_SRC_DIR/types

echo "nnvg version: "
nnvg --version
echo ""

echo "Generating code..."
nnvg --experimental-languages \
  --language-standard=c++17 \
  --target-language cpp \
  --pp-max-emptylines=1  \
  --pp-trim-trailing-whitespace \
  --target-endianness=any \
  --lookup-dir $PUBLIC_DATA_TYPES_DIR/uavcan \
  --outdir $OUTPUT_DIR \
  $RR_DATA_TYPES_DIR

echo "Copying code to destination"
rm -rf $HEADER_DIR/rr_data_types
cp -R $OUTPUT_DIR/rr_data_types "$HEADER_DIR"


echo "Fixing include paths"
cd $HEADER_DIR
find . -type f -exec sed -i 's/"reg\//<types\/reg\//g' {} +
find . -type f -exec sed -i 's/"uavcan\//"types\/uavcan\//g' {} +
find . -type f -exec sed -i 's/<nunavut/<nunavut/g' {} +
find . -type f -exec sed -i 's/.hpp>/.hpp>/g' {} +

echo "Auto-generate DSDL_Types.h.impl which contains a list of all generated files"
cd $CYPHAL_SRC_DIR
touch DSDL_Types.h.impl
truncate -s 0 DSDL_Types.h.impl
for i in $(find ./types -type f -name "*.hpp" -printf "%P\n")
do
  printf "#include \"types/%s\" \n" $i >> DSDL_Types.h.impl
done
