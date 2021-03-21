using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ItemCan : MonoBehaviour
{
    public float rotateSpeed;

    void Update()
    {
        transform.Rotate(new Vector3(5, 6) * rotateSpeed * Time.deltaTime, Space.World);
    }


}
