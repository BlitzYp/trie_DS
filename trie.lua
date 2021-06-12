function CreateTrie() 
    return {["connections"] = {}}
end

function AddValue(key, value, root) 
    local curr = root
    for i=1, #key do
        local index = string.byte(key, i) % 26
        if curr.connections[index] == nil then
            curr.connections[index] = CreateTrie()
        end
        curr = curr.connections[index]
    end
    curr.leaf = {["value"] = value, ["key"] = key}
end

function GetValue(key, root) 
    local curr = root
    for i=1, #key do
        local index = string.byte(key, i) % 26
        if curr.connections[index] == nil then
            return nil
        end
        curr = curr.connections[index]
    end
    return curr.leaf.value 
end

local trie = CreateTrie() 
AddValue("Dad", 234, trie)
print(GetValue("Dad", trie))
