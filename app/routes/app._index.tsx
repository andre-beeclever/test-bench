import { useCallback, useEffect, useMemo, useState } from "react";
import type { ActionFunctionArgs, LoaderFunctionArgs } from "@remix-run/node";
import { json } from "@remix-run/node";
import { useActionData, useNavigation, useSubmit } from "@remix-run/react";
import {
  Page,
  Layout,
  Text,
  Card,
  Button,
  BlockStack,
  Box,
  List,
  Link,
  InlineStack,
} from "@shopify/polaris";
import { TitleBar, useAppBridge } from "@shopify/app-bridge-react";
import { authenticate } from "../shopify.server";
import logger from "~/logger.server";
import { useTranslation } from "react-i18next";
import i18n from '~/i18n.server'
import { ShopifyAPI } from "clever_tools";
import { addEdge, Background, BackgroundVariant, Controls, Edge, MiniMap, Node, NodeToolbar, Panel, ReactFlow, ReactFlowInstance, ReactFlowJsonObject, useEdgesState, useNodesState } from '@xyflow/react';
import '@xyflow/react/dist/style.css';
import { ActionNode } from "~/components/ActionNode";
import { EntryNode } from "~/components/EntryNode";
import { ConditionNode } from "../components/ConditionNode";

export const loader = async ({ request }: LoaderFunctionArgs) => {
  await authenticate.admin(request);

  logger.info('Logger info demo')
  logger.warn('Logger warn demo')
  logger.error('Logger error demo')
  logger.debug('Logger debug demo')

  return null;
};

export const action = async ({ request }: ActionFunctionArgs) => {
  const { admin } = await authenticate.admin(request);
 
  return json({
   
  });
};

enum ComparisonOperator{
  less = "<",
  lessEqual = "<=",
  equal = "==",
  greaterEqual = ">=",
  greater = ">",
  notEqual = "!=",
}

type ComparisonFunction = (a: any, b: any) => boolean;

const ComparisonFunctions: { [key in ComparisonOperator]: ComparisonFunction } = {
  [ComparisonOperator.less]: (a, b) => a < b,
  [ComparisonOperator.lessEqual]: (a, b) => a <= b,
  [ComparisonOperator.equal]: (a, b) => a == b,
  [ComparisonOperator.greaterEqual]: (a, b) => a >= b,
  [ComparisonOperator.greater]: (a, b) => a > b,
  [ComparisonOperator.notEqual]: (a, b) => a != b
}

// enum LogicOperator{
//   and = "&&",
//   or = "||",
//   not = "!"
// }

// type LogicFunction = ((a: any, b: any) => boolean) | ((a: any) => boolean);

interface FlowSyntaxTree{
  entry: Entry
}

interface Condition{
  type: "Condition"
  a: any
  b: any
  operator: ComparisonOperator
  then?: Action | Condition
  else?: Action | Condition
}

interface Entry{ 
  type: "Entry"
  then?: Action | Condition
}

type ActionFunction = (...args: any[]) => any
interface Action{
  type: "Action"
  onAction: ActionFunction
  then?: Action | Condition
}


const testConditionA: Condition = { type: "Condition", a: 2, b: 4, operator: ComparisonOperator.lessEqual}

function testCondition(condition: Condition){
  return ComparisonFunctions[condition.operator](condition.a, condition.b)
}

interface EntryNode extends Node{
  type: "EntryNode"
  data: {
    label: string,
    input: any
  }
}

interface ActionNode extends Node{
  type: "ActionNode"
  data: {
    label: string,
    actionKey: string // get function via map
  }
}

interface ConditionNode extends Node{
  type: "ConditionNode"
  data: {
    label: string,
    a: string, // a key of global data
    b: string, // a key of global data
    operator: ComparisonOperator,
  }
}

const initialNodes = [
  { id: '1', type: "EntryNode", position: { x: 50, y: 50 }, data: { label: 'Entry', input: { a: 3, b: 5, c: "Hello" } } },
  { id: '2', type: "ConditionNode", position: { x: 150, y: 50 }, data: { label: 'Condition' } },
  { id: '3', type: "ActionNode", position: { x: 350, y: 50 }, data: { label: 'Action', actionKey: "actionKey" } },
];
const initialEdges = [
  { id: 'e1-2', source: '1', target: '2' },
  { id: 'e2-3', source: '2', target: '3' },
];

const functionMap: { [key: string]: ActionFunction } = {
  "actionKey": () => { console.log("hello") }
}


export default function Index() {
  const { t } = useTranslation();
  const nav = useNavigation();
  const actionData = useActionData<typeof action>();
  const submit = useSubmit();
  const shopify = useAppBridge();
  const isLoading = ["loading", "submitting"].includes(nav.state) && nav.formMethod === "POST";

  const [nodes, setNodes, onNodesChange] = useNodesState(initialNodes);
  const [edges, setEdges, onEdgesChange] = useEdgesState(initialEdges);
  const [rfInstance, setRfInstance] = useState<ReactFlowInstance | null>(null);

  const nodeTypes = useMemo(() => ({ ActionNode, EntryNode, ConditionNode }), []);

  console.log("testCondition", testCondition(testConditionA))

  const globalData = { input: {}}

  const constructFlowSyntaxBranch = (node: ActionNode | ConditionNode, flow: ReactFlowJsonObject) : (Action | Condition) => {
    if(node.type == "ActionNode"){
      const thenEdge = flow.edges.find(edge => edge.source == node.id)
      const thenNode = flow.nodes.find(node => node.id == thenEdge?.target)
      
      if(!thenEdge || !thenNode) return {
        type: "Action",
        onAction: functionMap[node.data.actionKey]
      }; 
      return {
        type: "Action",
        onAction: functionMap[node.data.actionKey],
        then: constructFlowSyntaxBranch(thenNode as ActionNode, flow)
      }
    }
    if(node.type == "ConditionNode"){
      const thenEdge = flow.edges.find(edge => edge.source == node.id)
      const thenNode = flow.nodes.find(node => node.id == thenEdge?.target)
      
      if(!thenEdge || !thenNode) return {
        type: "Condition",
        a: node.data.a,
        b: node.data.b,
        operator: node.data.operator
      }; 
      return {
        type: "Condition",
        a: node.data.a,
        b: node.data.b,
        operator: node.data.operator,
        then: constructFlowSyntaxBranch(thenNode as ActionNode, flow)
      }
    }
   
    throw "Unsupported node type"
    
  }

  const constructFlowSyntaxTree = (flow: ReactFlowJsonObject): FlowSyntaxTree => {
    const entryNode = flow.nodes.find(node => node.type == "EntryNode")
    if(!entryNode) throw "Could not find entry node."
    
    const thenEdge = flow.edges.find(edge => edge.source == entryNode.id)
    const thenNode = flow.nodes.find(node => node.id == thenEdge?.target)
    if(!thenEdge || !thenNode) return {
       entry: {
        type: "Entry",
       }
    }; 

    globalData.input = { ...(entryNode?.data.input ?? {}) }
  
    return {
      entry: {
        type: "Entry",
        then: constructFlowSyntaxBranch(thenNode as ActionNode, flow)
      }
    }
  }
  function runNode(node: Action | Condition){
    if(node.type == "Action"){
      node.onAction()
      if(!node.then) return;
      return runNode(node.then)
    }
    if(node.type == "Condition"){
      
    }
    
  }
  function run(flow: FlowSyntaxTree){
    if(!flow.entry.then) return;
    runNode(flow.entry.then)
  }


  const onPrint = useCallback(() => {
    if (!rfInstance) return;
    // @ts-ignore
    const flow = rfInstance.toObject();
    
    const fst = constructFlowSyntaxTree(flow)
    console.log(flow, globalData, fst)
    run(fst)
    
  }, [rfInstance]);
 
  const onConnect = useCallback((params: any) => 
    setEdges((eds) => addEdge(params, eds)
  ), [setEdges],
  );
  
  return (
    <Page title={t('hello')}>
     
      <BlockStack gap="500">
        <Layout>
          <Layout.Section>
            <Card padding={"200"}>
              <BlockStack gap="500">
                <div style={{width: "100%", height: "400px"}}>
                  <ReactFlow 
                    nodes={nodes}
                    edges={edges}
                    onNodesChange={onNodesChange}
                    onEdgesChange={onEdgesChange}
                    onConnect={onConnect}
                    nodeTypes={nodeTypes}
                    // @ts-ignore
                    onInit={setRfInstance}
                    fitView
                  >
                      <Panel position="top-right">
                        <Button onClick={onPrint}>print</Button>
                      </Panel>
                      <Controls />
                      <MiniMap />
                      <Background variant={BackgroundVariant.Dots} gap={12} size={1} />
                  </ReactFlow>
                </div>
              </BlockStack>
            </Card>
          </Layout.Section>
        </Layout>
      </BlockStack>
    </Page>
  );
}
