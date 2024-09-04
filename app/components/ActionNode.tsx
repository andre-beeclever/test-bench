import React, { useCallback, useEffect } from "react";
import { memo } from 'react';
import { Handle, Position, NodeToolbar } from '@xyflow/react';
import { Box, Card, Text } from "@shopify/polaris";
 
export function ActionNode({ data }: any){
  return (
    <Box background="bg-surface" borderColor="border" borderWidth="025" borderRadius="100">
       {/* <Text as="p">ActionNode</Text> */}
      {/* <NodeToolbar isVisible={data.toolbarVisible} position={data.toolbarPosition}>
        <button>delete</button>
        <button>copy</button>
        <button>expand</button>
      </NodeToolbar> */}
 
      <div style={{ padding: '10px 20px' }}>
        {data.label}
      </div>
 
      <Handle type="target" position={Position.Left}  />
      <Handle type="source" position={Position.Right} />
    </Box>
  );
};
 
export default memo(ActionNode);